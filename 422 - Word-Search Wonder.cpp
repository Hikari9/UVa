/**
	UVa 422 - Word Search Wonder
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.015s C++
	O(n^2) time
*/
// #include<iostream>
#include<cstdio>
using namespace std;
int n, i, j, k, l;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
char buf[105], c[105][105];
bool finds(){
	for( k=0; k<8; ++k ){
		for( l=1; buf[l]; ++l ){
			if( c[i+l*dx[k]][j+l*dy[k]] != buf[l] ) goto cont;
		}
		// found
		--l;
		printf( "%d,%d %d,%d\n", i, j, i+l*dx[k], j+l*dy[k] );
		return true;
		cont: continue;
	}
	return false;
}
int main(){
	scanf( "%d", &n );
	for( i=1; i<=n; ++i ){
		scanf( "%s", c[i]+1 );
	}
	next: while( scanf( "%s", buf ), buf[0]!='0' ){
		for( i=1; i<=n; ++i ){
			for( j=1; j<=n; ++j ){
				if( c[i][j]==buf[0] ){
					// search
					if( finds() ) goto next;
				}
			}
		}
		puts( "Not found" );
	}
}
