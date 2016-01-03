/**
	UVa 11341 - Term Strategy
	by Rico Tiongson
	Submitted: Feb 3, 2014
	Accepted 0.015s C++
	O(n^3) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n, m;

int L[11][101];
int dp[11][101];

int DP( int x, int y ){
	if( x < 0 ) return 0;
	if( ~dp[x][y] ) return dp[x][y];
	int ans = -10000;
	for( int i=0; i<y; ++i ){
		if( L[x][i] < 5 ) continue;
		int temp = DP( x-1, y-i-1 );
		if( temp < 0 ) continue;
		ans = max( ans, temp + L[x][i] );
	}
	return dp[x][y] = ans;
}

int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d %d", &n, &m );
		for( int i=0; i<n; ++i ){
			for( int j=0; j<m; ++j ){
				scanf( "%d", L[i] + j );
			}
		}
		memset( dp, -1, sizeof dp );
		int ans = -10000;
		for( int i=0; i<=m; ++i ){
			ans = max( ans, DP( n-1, i ) );
		}
		if( ans < 0 )
			puts( "Peter, you shouldn't have played billiard that much." );
		else
			printf( "Maximal possible average mark - %.2lf.\n", (double)(1e-9+ans)/n );
	}
}
