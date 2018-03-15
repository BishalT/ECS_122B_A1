#ifndef _BOYER_MOORE_PREPROCESSING_H_
#define _BOYER_MOORE_PREPROCESSING_H_

#include <map>
#include <string>
#include <vector>

// Input: Pattern P, alphabet Sigma, data structures to store L', l', R
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      Sigma is 0-indexed, treated as a set of characters
// Output: Pre-processing arrays for the Boyer-Moore Algorithm.
// 			Lprime[i] = L'(i)		(Defined p.20 Gusfield)
// 			lprime[i] = l'(i)		(Defined p.21 Gusfield)
// 			R[x] = R(x) 				(Defined p.17 Gusfield)
void BoyerMoorePreprocessing(
	const std::string& P,
	const std::string& Sigma,
	std::vector<int>* Lprime,
	std::vector<int>* lprime,
	std::map<char, int>* R);

// Input: Pattern P, N values, data structure to store result Lprime[i] = L'(i)
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      N is 1-indexed, so N[j] = Nj(P)
// Output: Lprime[i] = L'(i)) for all 1 <= i <= n, where n is the length of P
// 			L'(i) is the largest position less than n such that P[i, n] matches
// 			  a suffix of P[i, L'(i)] and the character preceding that suffix
// 			  differs from P(i - 1), or 0 if no such position exists.
void CalculateCapitalLprime(const std::string& P, const std::vector<int>& N, std::vector<int>* Lprime);

// Input: Pattern P, N values, data structure to store result lprime[i] = l'(i)
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      N is 1-indexed, so N[j] = Nj(P)
// Output: lprime[i] = l'(i) for all 1 <= i <= n, where n is the length of P
// 			l'(i) is the largest j <= n - i +1 such that Nj(P) = j
void CalculateLowercaseLprime(const std::string& P, const std::vector<int>& N, std::vector<int>* Lprime);

// Input: Pattern P, data structure to store result N[j] = Nj(P)
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
// Output: N[j] = Nj(P) for all 1 <= i <= n, where n is the length of P
// 			Nj(P) is the length of the longest suffix of P[i, j] that is also
// 			a suffix of P
void CalculateN(const std::string& P, std::vector<int>* N);

// Input: Pattern P, alphabet Sigma, data structure to store result R[i] = R(i)
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
// Output: R[x] = R(x) for all characters x in Sigma
// 			R(x) is the right-most occurrence of x in P, or 0 if it does not occur in P
void CalculateR(const std::string& P, const std::string& Sigma, std::map<char, int>* R);

#endif  // _BOYER_MOORE_PREPROCESSING_H_