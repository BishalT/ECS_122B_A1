#include "Zalgorithm.h"
#include "gtest/gtest.h"

#include <string>

using testing::Test;
using namespace::std;

// Testing MatchLength calculation when no matches occur
TEST(MatchLengthTest, NoMatchTest) {
  string P = " lul";
  string T = " kappaPride";
  list<int> matches;
  ZalgorithmBasedMatching(P, T, &matches);\
  EXPECT_EQ(matches.size(), 0);
}

// Testing MatchLength calculation when geginning of string matches
TEST(MatchLengthTest, BeginningStringMatch) {
  string P = " kappa";
  string T = " kappaPride";
  list<int> matches;
  ZalgorithmBasedMatching(P, T, &matches);\
  EXPECT_EQ(matches.size(), 1);
}

// Testing MatchLength calculation when middle of the string matches
TEST(MatchLengthTest, MidStringMatch) {
  string P = " paP";
  string T = " kappaPride";
  list<int> matches;
  ZalgorithmBasedMatching(P, T, &matches);\
  EXPECT_EQ(matches.size(), 1);
}

// Testing MatchLength calculation when match stops at end of string
TEST(MatchLengthTest, EndOfStringMatch) {
  string P = " Pride";
  string T = " kappaPride";
  list<int> matches;
  ZalgorithmBasedMatching(P, T, &matches);
  EXPECT_EQ(matches.size(), 1);
}

// Testing Zalgorithm calculation with string S = " aabcaabxaaz", p.7 Gusfield
TEST(ZalgorithmTest, GusfieldExamplePageSeven) {
  string T = " aabcaabxaaz";
  vector<int> tableZ;
  bool trueStatus = true;
  Zalgorithm(T, &tableZ);
  EXPECT_EQ(tableZ.operator[](5), 3);
  EXPECT_EQ(tableZ.operator[](6), 1);
  EXPECT_EQ(tableZ.operator[](7), 0);
  EXPECT_EQ(tableZ.operator[](8), 0);
  EXPECT_EQ(tableZ.operator[](9), 2);
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
