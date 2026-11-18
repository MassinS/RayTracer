#include "hello.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("hello_message returns Hello World")
{
    REQUIRE(hello_message() == "Hello, World!");
}
