cmake_minimum_required(VERSION 3.20.0)

set (Sources
    geneticTests.cpp
)

add_executable(tests ${Sources})
target_link_libraries(tests PUBLIC
    gtest_main
    RUST_GENES
)

add_test(
    NAME geneticTests
    COMMAND tests
)
