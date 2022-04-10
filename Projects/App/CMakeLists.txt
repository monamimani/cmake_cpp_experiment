
add_executable(App
    App/main.cpp)

target_link_libraries(App
    PRIVATE 
        ALib
        GTest::gmock 
        GTest::gtest
        benchmark::benchmark
)

gtest_discover_tests(App)