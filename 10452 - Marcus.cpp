/**
	UVa 10452 - Marcus
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.019s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
using namespace std;
const char* dir[] = {"forth", "right", "left"};
char I[] = "AVOHEI@";
char grid[10][10];
int t, m, n, i, dx[] = {1,0,0}, dy[] = {0,-1,1};
bool inRange( int x, int y ){
	return x>=0 && y>=0 && x<m && y<n;
}
bool dfs( int x, int y, int d ){
	if( d==7 ){
		return true;
	}
	for( int k=0; k<3; ++k ){
		if( inRange( x+dx[k], y+dy[k] ) && I[d]==grid[x+dx[k]][y+dy[k]] ){
			if( dfs( x+dx[k], y+dy[k], d+1 ) ){
				printf(dir[k]);
				if( d ) putchar(' ');
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf( "%d\n", &t);
	while( t-- ){
		scanf("%d %d\n",&m,&n);
		for( i=0; i<m; ++i ){
			gets( grid[i] );
		}
		for( i=0; i<n; ++i ){
			if( grid[0][i]=='#' ){
				break;
			}
		}
		dfs( 0, i, 0 );
		putchar('\n');
	}
}
