/**
	UVa 10285 - Longest Run on a Snowboard
	by Rico Tiongson
	Submitted: September 13, 2013
	Accepted 0.023s C++
	O(n^2) time
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[1005];
int n, r, c, i, j, mx;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int adj[105][105];
int dp[105][105];
inline bool inRange( int x, int y ){
	return x>=0 && y>=0 && x<r && y<c;
}
int top_down( int x, int y ){
	// if( !inRange(x,y) ) return 0;
	if( dp[x][y]!=-1 ) return dp[x][y];
	dp[x][y] = 1;
	for( int k=0; k<4; ++k ){
		if( inRange( x+ dx[k], y+ dy[k] ) && adj[x+ dx[k]][y+ dy[k]] < adj[x][y] ){
			dp[x][y] = max( dp[x][y], top_down( x+dx[k], y+dy[k] ) + 1 );
		}
	}
	return dp[x][y];
}
int ans(){
	memset( dp, -1, sizeof dp );
	mx = 0;
	for( i=0; i<r; ++i ){
		for( j=0; j<c; ++j ){
			mx = max( mx, top_down(i,j) );
		}
	}
	return mx;
}
int main(){
	scanf( "%d", &n );
	while(n--){
		scanf( "%s %d %d", str, &r, &c );
		for( i=0; i<r; ++i ){
			for( j=0; j<c; ++j ){
				scanf( "%d", adj[i]+j );
			}
		}
		printf( "%s: %d\n", str, ans() );
	}
}
