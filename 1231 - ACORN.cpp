#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c, t, h, f;
int dp[2005];
int acorn[2005][2005];

int DP( int );
int Acorns( int, int );


int main() {
	scanf( "%d", &c );
	while( c-- > 0 ){
		scanf( "%d%d%d", &t, &h, &f );
		memset( acorn, 0, sizeof acorn );
		memset( dp, -1, sizeof dp );
		for( int i=0; i<t; ++i ){
			int a, height;
			scanf( "%d", &a );
			for( int j=0; j<a; ++j ){
				scanf( "%d", &height );
				acorn[i][height]++;
			}
		}
		// recursive
		// printf( "%d\n", DP(h) );
		// iterative
		for( int i=0; i<=h; ++i )
			dp[i] = 0;
		for( int j=1; j<=h; ++j ){
			for( int i=0; i<t; ++i ){
				acorn[i][j] += max( acorn[i][j-1], dp[j-f >= 0 ? j-f : 0] );
				dp[j] = max( dp[j], acorn[i][j] );
			}
		}
		// cout << dp[h] << endl;
		printf( "%d\n", dp[h] );
	}
}

int DP( int height ){
	if( height <= 0 ) return 0;
	if( dp[height] != -1 ) return dp[height];
	int ans = 0;
	for( int i=0; i<t; ++i ){
		ans = max( ans, max( DP(height-f), Acorns(i, height) ) );
	}
	return dp[height] = ans;
}

int Acorns( int tree, int height ){
	if( height <= 0 ) return 0;
	return acorn[tree][height] + max( Acorns( tree, height-1 ), DP( height-f ) );
}