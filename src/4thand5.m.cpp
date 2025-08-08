#include <chrono>
#include <csignal>
#include <iostream>
#include <ncurses.h>
#include <string>

#include "feed.h"
#include "game_state.h"

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
    GameState gameState {
        .homeTeamId = 0,
        .awayTeamId = 0,
        .homeTeamScore = 0,
        .awayTeamScore = 0,
        .homeTeamTO = 3,
        .awayTeamTO = 3,
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

    // Input + Render
    (void)printw(std::to_string(gameState.homeTeamId).c_str());
    (void)printw(std::to_string(gameState.awayTeamId).c_str());
    (void)printw(std::to_string(gameState.homeTeamScore).c_str());
    (void)printw(std::to_string(gameState.awayTeamScore).c_str());
    (void)printw(std::to_string(gameState.homeTeamTO).c_str());
    (void)printw(std::to_string(gameState.awayTeamTO).c_str());
    (void)printw(std::to_string(gameState.down).c_str());
    (void)printw(std::to_string(gameState.distance).c_str());
    (void)printw(std::to_string(gameState.yardLine).c_str());
    (void)printw(std::to_string(gameState.period).c_str());
    (void)printw(std::to_string(gameState.clock.count()).c_str());
    (void)refresh();
    int ch = getch();
    (void)printw(std::to_string(ch).c_str());

    // Cleanup
    (void)endwin();

    return 0;
}

