#include <iostream>
#include <ncurses.h>
#include <string>

#include "feed.h"

using namespace fourthandfive;

int main()
{
    initscr(); // Start curses mode
    printw(std::to_string(getGameData(0)).c_str());
    refresh(); // Print it to the real screen
    getch();   // Wait for user input
    endwin();  // End curses mode
    return 0;
}

