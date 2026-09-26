#include "feed.h"

#include <curl/curl.h>

#include <cstdlib>
#include <chrono>
#include <mutex>

namespace fourthandfive {
namespace {

    void ensure_curl_init_cleanup() {
        static std::once_flag initFlag;
        std::call_once(initFlag, []() {
            curl_global_init(CURL_GLOBAL_ALL);
            std::atexit(curl_global_cleanup);
        });
    }

} // close namespace unnamed

std::vector<GameData> getGameData(const int gameId) {
    std::vector<GameData> gameData;

    ensure_curl_init_cleanup();

    return gameData;
}

} // close namespace fourthandfive

