cmake_minimum_required(VERSION 3.28)
project(CppProject)

set(CMAKE_CXX_STANDARD 17)

# This downloads the GoogleTest library for writing unit tests.
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/7d76a231b0e29caf86e68d1df858308cd53b2a66.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# This is where we list the .h (header) and .cpp (source) files in our program.
add_executable(Main
        src/main.cpp src/targetgame.cpp
        include/targetgame.h)
# Make the #include directive look inside our custom folder named "include".
target_include_directories(Main PUBLIC include)

enable_testing()
# We set up a second "executable" for the test cases. We should include all the headers and source
# files from the Main executable, except for the file that contains the main() function itself.
# We must also add any other file that has TEST() functions in it.
add_executable(TestCases
        src/targetgame.cpp test/tests.cpp
        include/targetgame.h)
target_include_directories(TestCases PUBLIC include)

# Link in the GoogleTest "main" to replace the default-generated "main". This will run the unit tests
# and report the output, instead of launching our application.
target_link_libraries(
        TestCases
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(TestCases)