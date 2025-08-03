#include <csignal>
#include <iostream>
#include <ncurses.h>
#include <string>

#include "feed.h"

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
    int gameData = getGameData(0);

    // Initialize rendering [ncurses]
    (void)initscr();
    (void)nonl();

    // Input + Render
    (void)printw(std::to_string(gameData).c_str());
    refresh();
    getch();

    // Cleanup
    (void)endwin();

    return 0;
}

