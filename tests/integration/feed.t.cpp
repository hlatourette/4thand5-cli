#include <catch2/catch.hpp>

#include "feed.h"

namespace fourthandfive {

TEST_CASE( "Test Game Data Feed", "[feed]" ) {
    REQUIRE( getGameData(0) == 42 );
}

} // close namespace fourthandfive

