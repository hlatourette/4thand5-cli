#ifndef FOURTHANDFIVE_FEED_H
#define FOURTHANDFIVE_FEED_H

#include <vector>

#include "game_data.h"

namespace fourthandfive {
    /**
     * @brief Get game data
     *
     * Retrieve game data from provider feed. 
     *
     * @param gameId Game ID
     * @return Game log
     */
    std::vector<GameData> getGameData(const int gameId);
} // close namespace fourthandfive

#endif /* FOURTHANDFIVE_FEED_H */

