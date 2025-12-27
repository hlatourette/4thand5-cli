#include "feed.h"

#include <chrono>

namespace fourthandfive {

std::vector<GameData> getGameData(const int gameId) {
    return {
        {
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
        }
    };
}

} // close namespace fourthandfive

