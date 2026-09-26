#include "feed.h"

#include <curl/curl.h>

#include <cstdlib>
#include <chrono>
#include <memory>
#include <mutex>
#include <string>

namespace fourthandfive {
namespace {

    CURLcode ensure_curl_init_cleanup() {
        CURLcode rc = CURLE_OK;
        static std::once_flag initFlag;
        (void)std::call_once(initFlag, [&rc]() {
            rc = curl_global_init(CURL_GLOBAL_ALL);
            std::atexit(curl_global_cleanup);
        });

        return rc;
    }

} // close namespace unnamed

std::vector<GameData> getGameData(const int gameId) {
    std::vector<GameData> gameData;
    CURLcode rc = ensure_curl_init_cleanup();
    if (rc == CURLE_OK) {
        std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> curl(curl_easy_init(), curl_easy_cleanup);
        if (curl) {
            std::string response;
            rc = curl_easy_perform(curl.get());
            if (rc == CURLE_OK) {
                // parseFeed(&gameData, const& response);
            }
        }
    }

    return gameData;
}

} // close namespace fourthandfive

