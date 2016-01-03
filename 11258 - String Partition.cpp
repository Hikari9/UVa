/**
	UVa 11258 - String Partition
	by Rico Tiongson
	Submitted: January 21, 2014
	Accepted 1.975s C++
	O(n^3 - pruning) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MX 201
using namespace std;
typedef unsigned long long lag;

int n;
char s[MX+5];
lag dp[MX][MX];
lag g[MX][MX];

lag G( int i, int j ){
	if( i > j || j - i + 1 > 10 ) return 0;
	if( ~g[i][j] ) return g[i][j];
	lag val = G(i, j-1) * 10uLL + s[j] - '0';
	if( val > 2147483647 ) val = 0;
	return g[i][j] = val;
}

lag DP( int i, int j ){
	if( i > j ) return 0;
	if( i == j ) return s[i] - '0';
	if( ~dp[i][j] ) return dp[i][j];
	lag val = G(i, j);
	if( val == 0 ){
		// cut left
		for( int k=1; k<=10 && i+k <= j; ++k ){
			val = max( val, G(i, i+k-1) + DP(i+k, j));
		}
		// cut right
		for( int k=1; k<=10 && j-k+1 > i; ++k ){
			val = max( val, G(j-k+1, j) + DP(i, j-k) );
		}
	}
	return dp[i][j] = val;
}

int main(){
	// cin >> n;
	scanf( "%d", &n );
	while( n-- ){
		// cin >> s;
		scanf( "%s", &s );
		memset( dp, -1, sizeof dp );
		memset( g, -1, sizeof g );
		printf( "%llu\n", DP(0, strlen(s)-1) );
		// cout << DP(0, s.length() - 1) << endl;
	}
}
