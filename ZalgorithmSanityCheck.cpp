#include "Zalgorithm.h"
#include "gtest/gtest.h"

using testing::Test;

#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 100000
#define RANDOM_STRING_SIZE 100

// Sanity check for ZalgorithmBasedMatching.
// Does NUM_TEST_CASES times:
//    1) Generate random string T of size RANDOM_STRING_SIZE
//    2) Generate a random substring P of T
//    3) Runs ZalgorithmBasedMatching and checks there is at least one match
// Use <random> & uniform_int_distribution for your random number generation
TEST(ZalgorithmSanityCheck, SubstringMatchesInRandomString) {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> letterDistribution(0, 25);
  std::uniform_int_distribution<int> substringDistribution(1, RANDOM_STRING_SIZE);
  for (int i = 0; i < NUM_TEST_CASES; i++) {
    std::string T = " ";
    for (int j = 0; j < RANDOM_STRING_SIZE; j++) {
      T.push_back('a' + letterDistribution(generator));
    }
    int start = substringDistribution(generator), end = substringDistribution(generator);
    if (start > end) {
      std::swap(start, end);
    }
    std::string P = " " + T.substr(start, end);
    std::list<int> matches;
    ZalgorithmBasedMatching(P, T, &matches);
    EXPECT_GE(matches.size(), 1);
  }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
