/**
	UVa 10926 - How Many Dependencies?
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.028s C++
	O(n^3) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool adj[105][105], v[105];
int t, tx;
int n, i, j, mx, mxi, c;
void dfs( int x ){
	if( v[x] ) return;
	v[x] = 1;
	for( int y=1; y<=n; ++y ){
		if( adj[x][y] ) dfs(y);
	}
}
int main(){
	while( scanf( "%d", &n )==1 && n ){
		memset( adj, 0, sizeof adj );
		for( i=1; i<=n; ++i ){
			scanf( "%d", &t );
			for( j=0; j<t; ++j ){
				scanf( "%d", &tx );
				adj[i][tx] = 1;
			}
		}
		mx = 0;
		mxi = 0;
		for( i=1; i<=n; ++i ){
			memset( v, 0, sizeof v );
			dfs(i);
			c = -1;
			for( j=1; j<=n; ++j )
				if(v[j]) ++c;
			if( mx < c ){
				mx = c;
				mxi = i;
			}
		}
		printf( "%d\n", mxi );
	}
}
