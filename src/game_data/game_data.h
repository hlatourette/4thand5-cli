#ifndef FOURTHANDFIVE_GAME_DATA_H
#define FOURTHANDFIVE_GAME_DATA_H

#include <chrono>

namespace fourthandfive {

struct GameData {
    unsigned int homeTeamId{0};
    unsigned int awayTeamId{0};
    unsigned int homeTeamScore{0};
    unsigned int awayTeamScore{0};
    unsigned int homeTeamTO{3};
    unsigned int awayTeamTO{3};
    unsigned int possession{0};
    unsigned int down{0};
    unsigned int distance{10};
    unsigned int yardLine{0};
    unsigned int period{0};
    std::chrono::seconds clock{900};
};

} // close namespace fourthandfive

#endif /* FOURTHANDFIVE_GAME_DATA_H */

