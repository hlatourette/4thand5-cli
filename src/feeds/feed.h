#ifndef FOURTHANDFIVE_FEED_H
#define FOURTHANDFIVE_FEED_H

#include <string>

namespace fourthandfive {
    /**
     * @brief Get game data
     *
     * Retrieve game data from provider feed. 
     *
     * @param gameId Game ID
     * @return Game data
     */
    int getGameData(const int gameId);
} // close namespace fourthandfive

#endif /* FOURTHANDFIVE_FEED_H */

