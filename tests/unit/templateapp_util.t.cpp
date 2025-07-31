#include <catch2/catch.hpp>

#include <templateapp_util.h>

namespace templateapp {

TEST_CASE( "The answer to life, the universe, and everything", "[templateapp_util]" ) {
    REQUIRE( meaningOfLifeTheUniverseAndEverything("What's the answer to the ultimate question?") == 42 );
}

} // close namespace templateapp
