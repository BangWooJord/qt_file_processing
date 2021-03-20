#define CATCH_CONFIG_MAIN
#include <Catch2-2.13.4/single_include/catch2/catch.hpp>
#include "file_related.h"

TEST_CASE("File length test", "[length]"){
    REQUIRE(file_length("../example_files/file1.bin") == 480622657);
    REQUIRE(file_length("../example_files/file2.bin") == 800000497);
    REQUIRE(file_length("../example_files/file3.bin") == 400000000);
    REQUIRE(file_length("../example_files/file4.bin") == 404400004);
}