/**
	UVa 11367 - Full Tank?
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 1.686s C++
	O(n^2logn) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define INF 2147483647
using namespace std;

struct edge{
	int i, w;
	edge() {}
	edge( int I, int W ): i(I), w(W) {}
};

struct node{
	int i, fuel, d;
	node() {}
	node( int I, int F, int D ): i(I), fuel(F), d(D) {}
	bool operator < ( const node& n ) const {
		return n.d < d || ( n.d == d && n.fuel < fuel );
	}
};

int n, m, p[1001], q, c, s, e;

vector<edge> adj[1001];
bool vis[101][1001];
unsigned path[101][1001];

int Dijkstra(){
	memset( path, -1, sizeof path );
	memset( vis, 0, sizeof vis );
	priority_queue<node> pq;
	path[0][s] = 0;
	pq.push( node(s, 0, 0) );
	while( !pq.empty() ){
		node top = pq.top(); pq.pop();
		if( vis[top.fuel][top.i] ) continue;
		vis[top.fuel][top.i] = true;
		// try add fuel
		if( top.fuel != c && !vis[top.fuel+1][top.i] ){
			int newPrice = top.d + ( p[top.i] );
			if( newPrice < path[top.fuel+1][top.i] ){
				path[top.fuel+1][top.i] = newPrice;
				pq.push( node(top.i, top.fuel+1, newPrice) );
			}
		}
		// try to go to adjacent roads
		for( int i=0; i<adj[top.i].size(); ++i ){
			int v = adj[top.i][i].i;
			int w = adj[top.i][i].w;
			if( top.fuel < w ) continue;
			int newFuel = top.fuel - w;
			if( !vis[newFuel][v] && path[newFuel][v] > top.d ){
				path[newFuel][v] = top.d;
				pq.push( node(v, newFuel, top.d) );
			}
		}
	}
	unsigned ans = path[0][e];
	for( int i=1; i<=c; ++i ){
		ans = min( ans, path[i][e] );
	}
	return ans;
}

int main(){
	int u, v, d;
	while( cin >> n >> m ){
		for( int i=0; i<n; ++i ){
			cin >> p[i];
			adj[i].clear();
		}
		for( int i=0; i<m; ++i ){
			cin >> u >> v >> d;
			adj[u].push_back( edge(v, d) );
			adj[v].push_back( edge(u, d) );
		}
		cin >> q;
		while(q--){
			cin >> c >> s >> e;
			int ans = Dijkstra();
			if( ans == -1 ) cout << "impossible" << endl;
			else cout << ans << endl;
		}
	}
}
