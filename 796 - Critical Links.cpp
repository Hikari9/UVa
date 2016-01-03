/**
	UVa 796 - Critical Links
	by Rico Tiongson
	Submitted: October 26, 2013
	Accepted 0.016s C++
	O(|V| + E) time
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, ID;
vector<int> id, low;
vector<vector<int> > adj;
vector<pair<int, int> > bridges;

void dfs( int u, int v ){
	id[v] = low[v] = ID++;
	for( int i=0; i<adj[v].size(); ++i ){
		int w = adj[v][i];
		if( id[w] == -1 ){
			dfs(v, w);
			low[v] = min( low[v], low[w] );
			if( low[w] == id[w] ){
				bridges.push_back( make_pair(min(v,w), max(v,w)) );
			}
		}
		else if( w != u ){
			low[v] = min( low[v], id[w] );
		}
	}
}

void tarjan(){
	bridges.clear();
	id.assign(n, -1);
	low.assign(n, -1);
	ID = 0;
	for( int i=0; i<n; ++i ){
		if( id[i] == -1 ) dfs(i, i);
	}
}

int main(){
	int u, m, v;
	while( scanf("%d", &n) == 1 ){
		adj.assign( n, vector<int>() );
		for( int i=0; i<n; ++i ){
			scanf( "%d (%d)", &u, &m );
			for( int j=0; j<m; ++j ){
				scanf( "%d", &v );
				adj[u].push_back(v);
			}
		}
		tarjan();
		sort( bridges.begin(), bridges.end() );
		printf( "%d critical links\n", bridges.size() );
		for( int i=0; i<bridges.size(); ++i ){
			printf( "%d - %d\n", bridges[i].first, bridges[i].second );
		}
		putchar('\n');
	}
}
