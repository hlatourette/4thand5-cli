#include <catch2/catch.hpp>

#include "feed.h"

namespace fourthandfive {

TEST_CASE( "Test Game Data Feed", "[feed]" ) {
    REQUIRE( getGameData(0).size() >= 0uz );
}

} // close namespace fourthandfive

