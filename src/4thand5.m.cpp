#include <chrono>
#include <csignal>
#include <iostream>
#include <ncurses.h>
#include <string>

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

    // Initialize data
    fourthandfive::GameState gameState {
        .homeTeamId = 0,
        .awayTeamId = 0,
        .homeTeamScore = 0,
        .awayTeamScore = 0,
        .homeTeamTO = 3,
        .awayTeamTO = 3,
        .possession = 0,
        .down = 0,
        .distance = 10,
        .yardLine = 0,
        .period = 0,
        .clock = std::chrono::seconds(900)
    };
    gameState.homeTeamId = getGameData(0);

    // Initialize rendering [ncurses]
    (void)initscr();
    (void)nonl();

    // Core loop [input processing + output rendering]
    const int cmdLimit = 5;
    char cmd[cmdLimit] = {0};
    while (true) {
        // Check window sizing
        int minX = 0, minY = 0, maxX = 0, maxY = 0;
        (void)getbegyx(stdscr, minY, minX);
        (void)getmaxyx(stdscr, maxY, maxX);
        // TODO: check window size meets minimum for rendering

        // Perform command
        // TODO: do logic updates

        // Buffer rendering
        (void)wmove(stdscr, minY, minX);
        (void)wclrtoeol(stdscr);
        (void)wprintw(stdscr, cmd);
        (void)wmove(stdscr, minY + 1, minX);
        (void)wprintw(stdscr, (std::to_string(minX) + " " + std::to_string(minY) + " " + std::to_string(maxX) + " " + std::to_string(maxY)).c_str());
        (void)wmove(stdscr, minY + 2, minX);
        (void)wclrtoeol(stdscr);

        // Reset cursor to input line and await command
        wmove(stdscr, minY + 2, minX);
        getnstr(cmd, cmdLimit);

        // Render output
        (void)wrefresh(stdscr);
    }

    // Cleanup
    (void)endwin();

    return 0;
}

