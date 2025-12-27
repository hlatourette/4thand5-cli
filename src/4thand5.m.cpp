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
    std::array<char, 959uz> configuration{};
    std::ifstream configFile("/usr/share/4thand5");
    if (configFile.is_open()) {
        (void)std::copy(std::istreambuf_iterator<char>(configFile), std::istreambuf_iterator<char>(), std::begin(configuration));
    }

    configFile.close();

    // Initialize data
    std::vector<fourthandfive::GameState> gameLog{};
    // gameLog = getGameData(0);

    // Initialize data views
    const std::size_t fieldViewRowSize = 137uz;
    const std::size_t fieldViewSize = fieldViewRowSize * 7uz;
    std::array<char, fieldViewSize> fieldView{};
    (void)std::copy(std::begin(configuration), std::end(configuration), std::begin(fieldView));

    // Initialize rendering [ncurses]
    (void)initscr();
    (void)nonl();

    // Core loop [input processing + output rendering]
    std::array<char, 5uz> cmd{};
    unsigned int minX = 0, minY = 0, maxX = 0, maxY = 0;
    while (true) {
        // Check window sizing
        (void)getbegyx(stdscr, minY, minX);
        (void)getmaxyx(stdscr, maxY, maxX);
        // TODO: window size minimums + resizing

        // Perform command
        // TODO: logic updates: cmd

        // Buffer rendering
        (void)wmove(stdscr, minY, minX);
        for (std::size_t fieldViewRow = 0; fieldViewRow < fieldView.size() / fieldViewRowSize; fieldViewRow++) {
            for (std::size_t fieldViewCol = 0; fieldViewCol < fieldViewRowSize; fieldViewCol++) {
                (void)wmove(stdscr, fieldViewRow, fieldViewCol);
                (void)waddch(stdscr, fieldView[(fieldViewRowSize * fieldViewRow) + fieldViewCol]);
            }
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

