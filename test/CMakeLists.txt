cmake_minimum_required(VERSION 3.20.0)

set (Sources
    geneticTests.cpp
)

add_executable(tests ${Sources})
target_link_libraries(tests PUBLIC
    gtest_main
    RUST_GENES
    gtest
)

# include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_test(
    NAME geneticTests
    COMMAND tests
)
# tedt