cmake_minimum_required (VERSION 3.2) # If your CMake version is older, try modifying this line
project(BoyerMoore)

add_definitions(-std=c++1z -g)

########## Create libraries
add_library(ZalgorithmLib Zalgorithm.cpp)
add_library(BoyerMoorePreprocessingLib BoyerMoorePreprocessing.cpp Zalgorithm.cpp)
########## TODO: Add library for BoyerMoore here (call it BoyerMooreLib)
add_library(BoyerMooreLib BoyerMoore.cpp)

########## Link GoogleTest
include_directories($ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/gtest/mybuild)

########## Add unit tests. The custom command runs the unit tests every time we use make to compile
add_executable(ZalgorithmTests ZalgorithmTests.cpp)
target_link_libraries(ZalgorithmTests gtest)
target_link_libraries(ZalgorithmTests pthread)
target_link_libraries(ZalgorithmTests ZalgorithmLib)
add_custom_command(TARGET ZalgorithmTests
                   POST_BUILD
                   COMMAND ZalgorithmTests
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   COMMENT "Running ZalgorithmTests" VERBATIM)

########## BOYERMOORE UNIT TEST
add_executable(BoyerMoorePreprocessingTests BoyerMoorePreprocessingTests.cpp)
target_link_libraries(BoyerMoorePreprocessingTests gtest)
target_link_libraries(BoyerMoorePreprocessingTests pthread)
target_link_libraries(BoyerMoorePreprocessingTests BoyerMoorePreprocessingLib)
add_custom_command(TARGET BoyerMoorePreprocessingTests
                   POST_BUILD
                   COMMAND BoyerMoorePreprocessingTests
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   COMMENT "Running BoyerMoorePreprocessingTests" VERBATIM)

########## Create sanity checks. These should not be run on every compile, so we only build it and run manually
add_executable(ZalgorithmSanityCheck ZalgorithmSanityCheck.cpp)
target_link_libraries(ZalgorithmSanityCheck gtest)
target_link_libraries(ZalgorithmSanityCheck pthread)
target_link_libraries(ZalgorithmSanityCheck ZalgorithmLib)

########## TODO: Add sanity check for BoyerMoore (call it BoyerMooreSanityCheck) here
add_executable(BoyerMooreSanityCheck BoyerMooreSanityCheck.cpp)
target_link_libraries(BoyerMooreSanityCheck gtest)
target_link_libraries(BoyerMooreSanityCheck pthread)
target_link_libraries(BoyerMooreSanityCheck BoyerMooreLib BoyerMoorePreprocessingLib)

########## TODO: Add sanity check for both algorithms (call it TwoAlgorithmVerificationSanityCheck) here
add_executable(TwoAlgorithmVerificationSanityCheck TwoAlgorithmVerificationSanityCheck.cpp)
target_link_libraries(TwoAlgorithmVerificationSanityCheck gtest)
target_link_libraries(TwoAlgorithmVerificationSanityCheck pthread)
target_link_libraries(TwoAlgorithmVerificationSanityCheck BoyerMooreLib BoyerMoorePreprocessingLib)
