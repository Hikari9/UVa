/**
	UVa 11022 - String Factoring
	by Rico Tiongson
	Submitted: January 21, 2014
	Accepted 0.015s C++
	O(n^3) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MX 81

using namespace std;

string s;
int dp[MX][MX];

int DP( int i, int j ){
	if( i > j ) return 0;
	if( i == j ) return 1;
	if( dp[i][j] != -1 ) return dp[i][j];
	int n = j - i + 1;
	// get minimum
	int val = n;
	for( int k=i; k<j; ++k ){
		val = min( val, DP( i, k ) + DP( k+1, j ) );
	}
	// try dividing into powers
	for( int g=1; g<n; ++g ){
		if( n % g == 0 ){
			// check
			for( int l=i+g; l<=j; l+=g ){
				for( int m=0; m<g; ++m ){
					if( s[i+m] != s[l+m] ){
						goto no;
					}
				}
			}
			// all equal
			val = min( val, DP(i, i+g-1) );
		}
		no:;
	}
	return dp[i][j] = val;
	
}

int main(){
	while( cin >> s, s != "*" ){
		memset( dp, -1, sizeof dp );
		cout << DP(0, s.length() - 1) << endl;
	}
}
