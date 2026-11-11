cmake_minimum_required(VERSION 3.28)

project(PocketLedger VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

enable_testing()

add_library(pocketledger_core STATIC 
    src/Transaction.cpp
)

target_include_directories(pocketledger_core PUBLIC include)

include(FetchContent)

FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.15.2
)

FetchContent_MakeAvailable(googletest)

add_executable(transaction_tests tests/TransactionTests.cpp)
target_link_libraries(transaction_tests PRIVATE pocketledger_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(transaction_tests)