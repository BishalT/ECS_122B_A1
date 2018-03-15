#include <list>
#include <string>
#include <vector>
#include <iostream>

#include "Zalgorithm.h"

/*
Z Algorithm
Input: A String S of length n
Output: Z[k] for all 2 <= k <= n

L = 0
R = 0

For k = 2 to N
	If k > R
		Z[k] <- matchLength( S, 1, k )
		If Z[k] != 0
			L = k
			R = L + Z[k] -1
		End IF
	Else
		R_1 = R - k + 1
		k’ = k - l + 1
		If Z[k’] < R_1
			Z[k] = Z[k’]
		Else
			q = r + MatchLength( S, R_1,  R )
			L = k
			r = q - 1
			Z[k] = q - k
		End If
	End For
Return Z[k]

MatchLength
Input: String S, int i, int j
Output: int length

result = 0;
	run loop while conditions:
 		i + result < S.length()
 		j + result < S.length()
 		S[ i + result ] == S [ j + result ]
 		result++
return result
*/

// Input: Pattern P, text T, data structure matches to store result
//      P is 1-indexed, so we represent the pattern "abc" by P = " abc"
//      T is also 1-indexed
// Output: Indices corresponding to occurrances of P in T
void ZalgorithmBasedMatching( const std::string& P, const std::string& T, std::list<int>* matches) {

	std::string S = P + T; 	// create string S with P$T

	std::vector<int> Z;
	Zalgorithm(S, &Z);	// call the Z algorithm
	//std::cout << Z.operator[](12) << std::endl;
	for( int index = 2; index < Z.size(); index++ ){
		//std::cout << Z.operator[](index) << " ";
		if ( Z.operator[](index) == P.size() - 1 ){	// if the Z value is equal to the size of P
				matches->push_back( index );	// push it into the matches list
		}
	}
}

// Input: String S, data structure Z to store result
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: Indices corresponding to occurrances of P in T
void Zalgorithm(const std::string& S, std::vector<int>* Z) {
	Z->push_back(0);	// Z[0] = 0, Indexing starts at 1
	Z->push_back(0);	// Z[1] = 0, Z-algorithm starts results at 2
	int l_value = 0, r_value = 0;
	for( int k = 2; k < S.length(); k++ ){
		if ( k > r_value ){
			int returned_val = MatchLength(S, 1, k);
			Z->push_back(returned_val);

			if( returned_val != 0 ){
				l_value = k;
				r_value = k + returned_val - 1;
			}
		}
		else {
			int R_val = r_value - k + 1;
			int k_prime = k - l_value + 1;
			if( Z->operator[](k_prime) < R_val ){
				Z->push_back( Z->operator[]( k_prime ) );
			}
			else{
				int q = r_value + MatchLength( S, R_val, r_value);
				l_value = k;
				r_value = q - 1;
				Z->push_back(q - k);
				//std::cout << q << " " << k << std::endl;
				//std::cout << Z->operator[](k) << std::endl;
			}
		}
	} // end for
} // end fn

// Input: String S, positions i and j of S
//      S is 1-indexed, so we represent the string "abc" by S = " abc"
// Output: length of longest common prefix of S[i, n] and S[j, n] where n = |S|
int MatchLength(const std::string& S, int i, int j) {
	int result;
	//std::cout << i << " " <<  j << std::endl;
	for( result = 0; i + result < S.length() && j + result < S.length() && S[ i + result ] == S[ j + result ]; result++ ) {} //std::cout << S[i+result] << S[j+result] << std::endl;}
	//std::cout << result << std::endl;
	return result;
}
/*
int main(){
	std::string P = " xxueoaun";
	std::string T = " vxxxueoaun";
	std::list<int> matches;
	ZalgorithmBasedMatching( P, T, &matches);
	std::cout << std::endl;
	for( int i : matches )
		std::cout << i << std::endl;

	return 0;
}
*/
