#define CATCH_CONFIG_MAIN
#include <Catch2-2.13.4/single_include/catch2/catch.hpp>
#include "file_related.h"
#include <thread>
#include "toml_related.h"

TEST_CASE("Toml reading function working correctly"){
    std::set<std::string> path;

    REQUIRE(openConfig("../../toml_cfg/cfg.toml", "paths", path) == true);

    REQUIRE(openConfig("random_txt", "text", path) == false);
}

TEST_CASE("File reading function working correctly"){
    long double data;

    REQUIRE(binary_read("../../example_files/file1.bin", data) == 0);

    REQUIRE(binary_read("random_text", data) < 0);
}
