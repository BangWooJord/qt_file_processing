#define CATCH_CONFIG_MAIN
#include <Catch2-2.13.4/single_include/catch2/catch.hpp>
#include "file_related.h"
#include <thread>
#include "toml_related.h"

TEST_CASE("Toml reading function working"){
    std::set<std::string> path;

    REQUIRE(openConfig("../../toml_cfg/cfg.toml", "paths", path) == true);
}

TEST_CASE("File reading OK"){
    long double data;

    std::thread test1([&](){
        REQUIRE(binary_read("../../example_files/file1.bin", data) == 0);
    });
    std::thread test2([&](){
        REQUIRE(binary_read("../../example_files/file2.bin", data) == 0);
    });
    std::thread test3([&](){
        REQUIRE(binary_read("../../example_files/file3.bin", data) == 0);
    });
    std::thread test4([&](){
        REQUIRE(binary_read("../../example_files/file4.bin", data) == 0);
    });
    REQUIRE(binary_read("random_text", data) < 0);
    test1.join();
    test2.join();
    test3.join();
    test4.join();
}
