/**
	UVa 193 - Graph Coloring
	by Rico Tiongson
	Submitted: June 23, 2013
	Accepted 0.022s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define mx 105
using namespace std;
int t, n, m, a, b, c, sz, black;
bool adj[mx][mx], vis[mx], isblack[mx], ans[mx], f;
void dfs( int x ){
	if( x==n ){
		// get all black
		if( black>sz ){
			sz = black;
			memcpy( ans, isblack, sizeof(ans) );
		}
		return;
	}
	if( vis[x] ){
		dfs(x+1);
		return;
	}
	// color myself white
	vis[x] = true;
	isblack[x] = false;
	dfs( x+1 );
	
	// color myself black
	++black;
	isblack[x] = true;
	// color all adjacents white
	bool revert[mx];
	memset( revert, 0, sizeof(revert) );
	for( b=x+1; b<n; ++b ){
		if( adj[x][b] && !vis[b] ){
			vis[b] = true;
			revert[b] = true;
			isblack[b] = false;
			// color it white
		}
	}
	dfs( x+1 );
	// revert
	--black;
	isblack[x] = false;
	for( b=x+1; b<n; ++b ){
		if( revert[b] ){
			vis[b] = false;
		}
	}
	vis[x] = false;
	// delete[] revert;
}
int main(){
	scanf("%d",&t);
	while( t ){
		scanf( "%d %d", &n, &m );
		memset( adj, 0, sizeof(adj) );
		memset( vis, 0, sizeof(vis) );
		memset( isblack, 0, sizeof(isblack) );
		while( m ){
			scanf("%d %d",&a,&b);
			adj[a][b] = adj[b][a] = true;
			--m;
		}
		++n;
		black = sz = 0;
		dfs( 1 );
		printf("%d\n", sz );
		f = false;
		for( a=1; a<n; ++a ){
			if( ans[a] ){
				if( f ) putchar(' ');
				else f = true;
				printf("%d",a);
			}
		}
		putchar('\n');
		--t;
	}
}
