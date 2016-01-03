/**
	UVa 11463 - Commandos
	by Rico Tiongson
	Submitted: October 27, 2013
	Accepted 0.046s ANSI C
	O(n^3) time
*/
#include<stdio.h>
#include<string.h>

int t, n, r, tc=0, i, j, k;
int path[101][101], start, end, mx;

int min( int a, int b ){ return a < b ? a : b; }
int max( int a, int b ){ return a > b ? a : b; }

int FloydWarshall(){
	for( k=0; k<n; ++k )
		for( i=0; i<n; ++i )
			for( j=0; j<n; ++j )
				path[i][j] = min( path[i][j], path[i][k] + path[j][k] );
	mx = 0;
	for( i=0; i<n; ++i )
		mx = max( mx, path[start][i] + path[i][end] );
	return mx;
}

int main(){
	scanf( "%d", &t );
	while( tc < t ){
		scanf( "%d", &n );
		scanf( "%d", &r );
		for( i=0; i<n; ++i ){
			for( j=0; j<n; ++j ){
				path[i][j] = 1000000000;
			}
			path[i][i] = 0;
		}
		
		while(r--){
			scanf( "%d %d", &i, &j );
			path[i][j] = path[j][i] = 1;
		}
		scanf( "%d %d", &start, &end );
		printf( "Case %d: %d\n", ++tc, FloydWarshall() );
	}
}
