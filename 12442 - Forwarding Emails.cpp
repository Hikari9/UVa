/**
	UVa 12442 - Forwarding Emails
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.232s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MX 50005
using namespace std;

int t, n, tc, d;
int link[MX], path[MX];
int cycle[MX], cy, root;

void dfs( int u ){
	if( cycle[u] != -1 ){
		root = d;
		cy = cycle[u];
		return;
	}
	if( path[u] != -1 ){
		cy = d - path[u];
		root = path[u];
		// cycle[u] = cy;
		return;
	}
	path[u] = d++;
	dfs( link[u] );
	cycle[u] = max( 0, root - path[u] ) + cy ;
	path[u] = -1;
}

int main(){
	int u, v;
	cin >> t;
	while( tc < t ){
		cin >> n;
		for( int i=1; i<=n; ++i ) link[i] = i;
		for( int i=1; i<=n; ++i ){
			cin >> u >> v;
			link[u] = v;
			path[i] = -1;
			cycle[i] = -1;
		}
		int ans = 1;
		for( int i=2; i<=n; ++i ){
			d = 0;
			dfs(i);
			if( cycle[ans] < cycle[i] ) ans = i;
		}
		printf( "Case %d: %d\n", ++tc, ans );
	}
}
