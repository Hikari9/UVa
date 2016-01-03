/**
	UVa 12144 - Almost Shortest Path
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.068s C++
	O(mnlogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 2000000000
using namespace std;

struct edge{
	int i, w;
	edge() {}
	edge( int I, int W ): i(I), w(W) {}
	bool operator < ( const edge& e ) const {
		return w > e.w;
	}
};

int n, m, s, d;
vector<edge> adj[501];
vector<int> prev[501];
bool vis[501], eVis[501][501];
int path[501];

int Dijkstra(){
	
	for( int i=0; i<n; ++i ){
		path[i] = INF;
		prev[i].clear();
		vis[i] = false;
	}
	
	priority_queue<edge> pq;
	path[s] = 0;
	pq.push( edge(s, 0) );
	
	while( !pq.empty() ){
		int u = pq.top().i;
		int W = pq.top().w;
		pq.pop();
		if( vis[u] ) continue;
		vis[u] = true;
		for( int j=0; j<adj[u].size(); ++j ){
			int v = adj[u][j].i;
			int w = adj[u][j].w;
			if( !vis[v] && !eVis[u][v] ) {
				if( W + w < path[v] ){
					path[v] = W + w;
					prev[v].clear();
					prev[v].push_back(u);
					pq.push( edge(v, path[v]) );
				}
				else if( W + w == path[v] ){
					prev[v].push_back(u);
				}
			}
		}
	}
	
	return path[d];
	
}

void close( int node ){
	for( int i=0; i<prev[node].size(); ++i ){
		eVis[prev[node][i]][node] = 1;
		close( prev[node][i] );
	}
}

bool test( int node ){
	if( eVis[node][d] ) return false;
	for( int i=0; i<prev[node].size(); ++i ){
		if( eVis[prev[node][i]][node] ) return false;
		if( !test( prev[node][i] ) ) return false;
	}
	return true;
}

int Find( const vector<edge>& e, int ff ){
	for( int i=0; i<e.size(); ++i ){
		if( e[i].i == ff ) return i;
	}
	return -1;
}

int main(){
	while( scanf( "%d %d", &n, &m ) == 2 && ( n || m ) ){
		scanf( "%d %d", &s, &d );
		for( int i=0; i<n; ++i ){
			adj[i].clear();
		}
		for( int i=0; i<m; ++i ){
			int a, b, c;
			scanf( "%d %d %d", &a, &b, &c );
			adj[a].push_back( edge( b, c ) );
		}
		memset( eVis, 0, sizeof eVis );
		int shortest = Dijkstra();
		close(d);
		int almostShortest = INF;
		if( shortest != INF ){
			while(true){
				almostShortest = Dijkstra();
				if( almostShortest > shortest ) break;
				close(d);
			}
		}
		
		if( almostShortest == INF ) puts("-1");
		else printf("%d\n", almostShortest );
	}
}
