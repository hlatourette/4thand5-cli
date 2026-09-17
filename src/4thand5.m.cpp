#include <algorithm>
#include <array>
#include <csignal>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ncurses.h>
#include <string>
#include <vector>

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
    std::array<char, 847uz> configuration{};
    configuration.fill(0x20);
    std::ifstream configFile("/usr/share/4thand5");
    if (configFile.is_open()) {
        (void)std::copy(std::istreambuf_iterator<char>(configFile), std::istreambuf_iterator<char>(), std::begin(configuration));
    }

    configFile.close();

    // Initialize data
    std::vector<fourthandfive::GameData> gameDataLog{};
    std::array<char, 5uz> cmd{};
    gameDataLog = getGameData(0);

    // Initialize data views
    View fieldView = createDefaultFieldView();
    View inputView = createDefaultInputView();
    (void)std::copy(std::begin(configuration), std::end(configuration), std::begin(fieldView.buffer));

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
        const bool fits =
            (maxY >= [](auto... args) { return (... + args); }(fieldView.nRows, inputView.nRows)) &&
            (maxX >= std::max({fieldView.nCols, inputView.nCols}));
        if (fits) {
            // TODO: iterate over view objects
            (void)wmove(stdscr, minY, minX);
            for (std::size_t viewRow = 0; viewRow < fieldView.nRows; viewRow++) {
                for (std::size_t viewCol = 0; viewCol < fieldView.nCols; viewCol++) {
                    (void)wmove(stdscr, viewRow, viewCol);
                    (void)waddch(stdscr, fieldView.buffer[(fieldView.nCols * viewRow) + viewCol]);
                }
            }
        } else {
            (void)werase(stdscr);
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

