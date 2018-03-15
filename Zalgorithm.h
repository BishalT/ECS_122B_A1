#ifndef _Z_ALGORITHM_H_
#define _Z_ALGORITHM_H_

#include <list>
#include <string>
#include <vector>

// Input: Pattern P, text T, data structure matches to store result
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      T is also 1-indexed
// Output: Indices corresponding to occurrances of P in T
void ZalgorithmBasedMatching(
    const std::string& P,
    const std::string& T,
    std::list<int>* matches);

// Input: String S, data structure Z to store result
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: Indices corresponding to occurrances of P in T
int MatchLength(const std::string& S, int i, int j);

// Input: String S, positions i and j of S
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: length of longest common prefix of S[i, n] and S[j, n] where n = |S|
void Zalgorithm(const std::string& S, std::vector<int>* Z);

#endif  // _Z_ALGORITHM_H_