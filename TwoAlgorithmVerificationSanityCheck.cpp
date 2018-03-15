#include "BoyerMoore.h"
#include "Zalgorithm.h"
#include "gtest/gtest.h"

using testing::Test;

#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 10000
#define RANDOM_STRING_SIZE 100
#define RANDOM_SUBSTRING_SIZE 4

// Sanity check for BoyerMoore & ZalgorithmBasedMatching
// Does NUM_TEST_CASES times:
//    1) Generate random string T of size RANDOM_STRING_SIZE
//    2) Generate a random substring P of T
//    3) Runs BoyerMoore and ZalgorithmBasedMatching and checks results are identical
// Use <random> & uniform_int_distribution for your random number generation

TEST(TwoAlgorithmVerificationSanityCheck, SubstringMatchesInRandomString) {
  std::default_random_engine le_gen;
  std::uniform_int_distribution<int> letterDist(0,25);
  std::uniform_int_distribution<int> substrDist(1,RANDOM_STRING_SIZE);
  for( int i = 0; i < NUM_TEST_CASES; i ++ ){
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::string T = " ";
    std::list<int> matchesZalg;
    std::list<int> matchesBoyer;
    for( int j = 0; j < RANDOM_STRING_SIZE; j++ ){
      T.push_back('z' + letterDist(le_gen));
    }
    int start = substrDist(le_gen), end = substrDist(le_gen);
    if( start > end )
      std::swap( start, end );
    std::string P = " " + T.substr(start, end);
    BoyerMoore( P, T, Sigma, &matchesBoyer );
    ZalgorithmBasedMatching( P, T, &matchesZalg );
    EXPECT_TRUE(matchesZalg.size() == matchesBoyer.size());
  }
}

// Sanity check for BoyerMoore & ZalgorithmBasedMatching
// Does NUM_TEST_CASES times:
//    1) Generate random string T of size RANDOM_STRING_SIZE
//    2) Generate a random substring P of size RANDOM_SUBSTRING_SIZE (no relationship to T)
//    3) Runs BoyerMoore and ZalgorithmBasedMatching and checks results are identical
// Use <random> & uniform_int_distribution for your random number generation
TEST(TwoAlgorithmVerificationSanityCheck, RandomSubstringVsRandomString) {
  std::default_random_engine le_gen;
  std::uniform_int_distribution<int> letterDist(0,25);
  std::uniform_int_distribution<int> substrDist(1,RANDOM_STRING_SIZE);
  for( int i = 0; i < NUM_TEST_CASES; i ++ ){
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::string T = " ";
    std::string P = " ";
    std::list<int> matchesZalg;
    std::list<int> matchesBoyer;
    for( int j = 0; j < RANDOM_STRING_SIZE; j++ ){
      T.push_back('z' + letterDist(le_gen));
    }
    for( int j = 0; j < RANDOM_STRING_SIZE; j++ ){
      P.push_back('z' + letterDist(le_gen));
    }
    BoyerMoore( P, T, Sigma, &matchesBoyer );
    ZalgorithmBasedMatching( P, T, &matchesZalg );
    EXPECT_TRUE(matchesZalg.size() == matchesBoyer.size());
  }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
