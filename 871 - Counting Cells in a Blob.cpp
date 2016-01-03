/**
	UVa 871 - Counting Cells in a Blob
	by Rico Tiongson
	Submitted: November 2, 2013
	Accepted 0.012s C++
	O(V+E) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int n, cnt, p;
char c[30][30];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inRange( int x, int y ){
	return x >= 0 && y >= 0 && x < p;
}

void dfs( int x, int y ){
	if( !inRange(x, y) || c[x][y] != '1' ) return;
	++cnt;
	c[x][y] = '0';
	for( int k=0; k<8; ++k )
		dfs( x + dx[k], y + dy[k] );
}

int main(){
	gets( c[0] );
	n = atoi( c[0] );
	gets( c[0] );
	while( n-- ){
		memset( c, 0, sizeof c );
		p = 0;
		while( gets( c[p] ) ){
			if( c[p][0] == '\0' ) break;
			++p;
		}
		int mx = 0;
		for( int i=0; i<p; ++i ){
			for( int j=0; c[i][j]; ++j ){
				if( c[i][j] == '1' ){
					cnt = 0;
					dfs( i, j );
					mx = max( cnt, mx );
				}
			}
		}
		cout << mx << endl;
		if( n ) cout << endl;
	}
}
