#include <algorithm>
#include <array>
#include <csignal>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <tuple>
#include <vector>

#include <ncurses.h>

#include "feed.h"
#include "game_data.h"
#include "view.h"

using namespace fourthandfive;

void signalHandler(int signum)
{
    (void)endwin();
    (void)exit(signum);
}

int main(int argc, char *argv[])
{
    if (argc < 1) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        return 1;
    }

    (void)std::signal(SIGINT, signalHandler);

    // Initialize configuration
    std::array<char, 1815uz> configuration{};
    configuration.fill(0x20);
    std::ifstream configFile("/usr/share/4thand5");
    if (configFile.is_open()) {
        auto fileRange = std::ranges::subrange(std::istreambuf_iterator<char>(configFile), std::istreambuf_iterator<char>());
        (void)std::ranges::copy(std::views::take(fileRange, configuration.size()), std::begin(configuration));
    }

    configFile.close();

    // Initialize data
    std::vector<fourthandfive::GameData> gameDataLog{};
    std::array<char, 5uz> cmd{};
    gameDataLog = getGameData(0);

    // Initialize data views
    View scoreView = createDefaultScoreView();
    View fieldView = createDefaultFieldView();
    (void)std::ranges::copy(std::views::take(configuration, fieldView.buffer.size()), std::begin(fieldView.buffer));
    std::tuple views{ std::cref(scoreView), std::cref(fieldView) };

    // Initialize rendering [ncurses]
    (void)initscr();
    (void)nonl();

    // Core loop [input processing + data updates + output buffering + output rendering]
    unsigned int minX = 0, minY = 0, maxX = 0, maxY = 0;
    while (true) {
        // Perform cmd + data updates
        // TODO: logic + data updates: cmd

        // Update view buffer
        // TODO: view updates

        // Check window sizing
        (void)getbegyx(stdscr, minY, minX);
        (void)getmaxyx(stdscr, maxY, maxX);

        // Buffer rendering
        (void)wmove(stdscr, minY, minX);
        const bool fits =
            (maxY >= std::apply([](auto... args) { return (... + args.get().nRows) + 1uz; }, views)) &&
            (maxX >= std::apply([](auto... args) { return std::max({args.get().nCols...}); }, views)); //TODO: pass cmd.size() for maxX check
        if (fits) {
            unsigned int startX = minX, startY = minY;
            (void)wmove(stdscr, startY, startX);
            std::apply([&startX, &startY](auto&&... args) {
                auto bufferView = [&](auto&& view) {
                    for (std::size_t viewRow = 0; viewRow < view.get().nRows; viewRow++) {
                        for (std::size_t viewCol = 0; viewCol < view.get().nCols; viewCol++) {
                            (void)wmove(stdscr, viewRow + startY, viewCol + startX);
                            (void)waddch(stdscr, view.get().buffer[(view.get().nCols * viewRow) + viewCol]);
                        }
                    }

                    startY += view.get().nRows;
                };

                ((void)bufferView(args), ...);
            }, views);
        } else {
            (void)wmove(stdscr, minY, minX);
            (void)werase(stdscr);
            (void)wprintw(stdscr, "Terminal too small to render...");
        }

        (void)wmove(stdscr, maxY - 1, minX);
        (void)wclrtoeol(stdscr);

        // Render output
        (void)wrefresh(stdscr);

        // Reset cursor to input await command
        (void)wmove(stdscr, maxY - 1, minX);
        (void)wgetnstr(stdscr, cmd.data(), cmd.size());
    }

    // Cleanup
    (void)endwin();

    return 0;
}

