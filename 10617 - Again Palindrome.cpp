/**
	UVa 10617 - Again Palindrome
	by Rico Tiongson
	Submitted: January 21, 2014
	Accepted 0.009s C++
	O(n^2) time
*/
#include <iostream>
#include <cstring>
#define MX 61
using namespace std;

string s;
long long dp[MX][MX];

long long DP( int i, int j ){
	if( i > j ) return 0;
	if( ~dp[i][j] ) return dp[i][j];
	long long val = DP( i+1, j ) + DP( i, j-1 ) - DP( i+1, j-1 );
	if( s[i] == s[j] ){
		val += 1 + DP( i+1, j-1 );
	}
	return dp[i][j] = val;
	
}

int main(){
	int n;
	cin >> n;
	while( n-- ) {
		cin >> s;
		memset( dp, -1, sizeof dp );
		cout << DP(0, s.length() - 1) << endl;
	}
}
