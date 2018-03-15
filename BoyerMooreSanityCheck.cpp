#include "BoyerMoore.h"
#include "gtest/gtest.h"

using testing::Test;

#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 10000
#define RANDOM_STRING_SIZE 100

// Sanity check for BoyerMoore.
// Does NUM_TEST_CASES times:
//    1) Generate random string T of size RANDOM_STRING_SIZE
//    2) Generate a random substring P of T
//    3) Runs BoyerMoore and checks there is at least one match
// Use <random> & uniform_int_distribution for your random number generation
TEST(BoyerMooreSanityCheck, SubstringMatchesInRandomString) {
  std::default_random_engine le_gen;
  std::uniform_int_distribution<int> letterDist(0,25);
  std::uniform_int_distribution<int> substrDist(1,RANDOM_STRING_SIZE);
  for( int i = 0; i < NUM_TEST_CASES; i ++ ){
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::string T = " ";
    std::list<int> matches;
    for( int j = 0; j < RANDOM_STRING_SIZE; j++ ){
      T.push_back('z' + letterDist(le_gen));
    }
    int begin = substrDist(le_gen), end = substrDist(le_gen);
    if( begin > end )
      std::swap( begin, end );
    std::string P = " " + T.substr(begin, end);
    BoyerMoore( P, T, Sigma, &matches );
    EXPECT_GE(matches.size(), 1);
  }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
