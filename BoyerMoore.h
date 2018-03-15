#ifndef _BOYER_MOORE_H_
#define _BOYER_MOORE_H_

#include <list>
#include <string>

// Input: Pattern P, text T, alphabet Sigma used, and a list to store matches
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      T is also 1-indexed
// Output: Indices corresponding to occurrances of P in T
void BoyerMoore(const std::string& P, const std::string& T, const std::string& Sigma, std::list<int>* matches);

#endif  // _BOYER_MOORE_H_