#define CATCH_CONFIG_MAIN
#include <Catch2-2.13.4/include/catch.hpp>

int sum(int x, int y){
    return x+y;
}

TEST_CASE("Sum of two elements", "[][sum]"){
    REQUIRE(sum(2,5) == 7);
}
