#include "BoyerMoorePreprocessing.h"
#include "gtest/gtest.h"

using testing::Test;

// Unit tests for BoyerMoorePreprocessing. Because unit tests are a first line
// of defense, ideally, each test should:
//  1) Be deterministic (For consistent results)
//  2) Test exactly one thing (To quickly diagnose bugs)
//  3) Run quickly, ex. ~0-1ms per test (To minimize overhead while compiling with make)

// Testing L' calculation with string P = " cabdabdab", P.20 Gusfield
TEST(CalculateCapitalLprimeTest, GusfieldExamplePageTwenty) {
  std::vector<int> N;
  //                123456789
  std::string P = " cabdabdab";
  CalculateN(P, &N);
  std::vector<int> Lprime;
  CalculateCapitalLprime(P, N, &Lprime);
  ASSERT_EQ(Lprime.size(), P.size());
  EXPECT_EQ(Lprime[1], 0);
  EXPECT_EQ(Lprime[2], 0);
  EXPECT_EQ(Lprime[3], 0);
  EXPECT_EQ(Lprime[4], 0);
  EXPECT_EQ(Lprime[5], 6);
  EXPECT_EQ(Lprime[6], 0);
  EXPECT_EQ(Lprime[7], 0);
  EXPECT_EQ(Lprime[8], 3);
  EXPECT_EQ(Lprime[9], 0);
}

// Testing L' calculation with string P = " dabcdbdab"
TEST(CalculateLowercaseLprimeTest, Pattern_dabcdbdab) {
  std::vector<int> N;
  //                123456789
  std::string P = " dabcdbdab";
  CalculateN(P, &N);
  std::vector<int> lprime;
  CalculateLowercaseLprime(P, N, &lprime);
  ASSERT_EQ(lprime.size(), P.size());
  EXPECT_EQ(lprime[1], 3);
  EXPECT_EQ(lprime[2], 3);
  EXPECT_EQ(lprime[3], 3);
  EXPECT_EQ(lprime[4], 3);
  EXPECT_EQ(lprime[5], 3);
  EXPECT_EQ(lprime[6], 3);
  EXPECT_EQ(lprime[7], 3);
  EXPECT_EQ(lprime[8], 0);
  EXPECT_EQ(lprime[9], 0);
}

// Testing N calculation with string P = " cabdabdab", p. 21 Gusfield
TEST(CalculateNTest, GusfieldExamplePageTwentyOne) {
  std::vector<int> N;
  //                123456789
  std::string P = " cabdabdab";
  CalculateN(P, &N);
  ASSERT_EQ(N.size(), P.size());
  EXPECT_EQ(N[3], 2);
  EXPECT_EQ(N[6], 5);
}

// Testing R calculation with an empty pattern P
TEST(CalculateRTest, EmptyPattern) {
	std::map<char, int> R;
	CalculateR(" ", "abc", &R);
  ASSERT_EQ(R.size(), 3);
  EXPECT_EQ(R['a'], 0);
  EXPECT_EQ(R['b'], 0);
  EXPECT_EQ(R['c'], 0);
}

// Testing R calculation with a pattern P that is a single character
TEST(CalculateRTest, SingleCharacterPattern) {
	std::map<char, int> R;
	CalculateR(" a", "ab", &R);
  ASSERT_EQ(R.size(), 2);
  EXPECT_EQ(R['a'], 1);
  EXPECT_EQ(R['b'], 0);
}

// Testing R calculation with a pattern P that has at least
//  one character that appears two or more times
TEST(CalculateRTest, RepeatedCharacterPattern) {
	std::map<char, int> R;
	CalculateR(" aba", "ab", &R);
  ASSERT_EQ(R.size(), 2);
  EXPECT_EQ(R['a'], 3);
  EXPECT_EQ(R['b'], 2);
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
