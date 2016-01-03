/**
	UVa 10557 - XYZZY
	by Rico Tiongson
	Submitted: October 18, 2013
	Accepted 0.032s C++
	O(?) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#define INF 2000000000
using namespace std;
struct edge{
	int u, v, w;
	edge() {}
	edge( int U, int V, int W ){
		u = U;
		v = V;
		w = W;
	}
};
int n;
vector<int> g;
vector<vector<int> > adj2;
vector<edge> adj;
bool dfs(int u){
	bool v[g.size()];
	memset( v, 0, sizeof v );
	stack<int> st;
	st.push(u);
	v[u] = true;
	while( !st.empty() ){
		int th = st.top(); st.pop();
		for( int j=0; j<adj2[th].size(); ++j ){
			int nx = adj2[th][j];
			if( !v[nx] ){
				v[nx] = true;
				st.push(nx);
			}
		}
	}
	return v[n];
}
bool BellmanFord(){
	int path[g.size()];
	int prev[g.size()];
	for( int i=1; i<=n; ++i ){
		path[i] = INF;
		prev[i] = -1;
	}
	path[1] = -100;
	for( int i=1; i<n; ++i ){
		for( int j=0; j<adj.size(); ++j ){
			int u = adj[j].u;
			int v = adj[j].v;
			int w = adj[j].w;
			if( path[u] + w < path[v] && path[u] + w < 0 ){
				path[v] = path[u] + w;
				prev[v] = u;
			}
		}
	}
	// for( int i=1; i<=n; ++i ){
		// cout << path[i] << " ";
	// }
	// cout << endl;
	if( path[n] < 0 ) return false;
	adj2.clear();
	adj2.resize(g.size());
	for( int j=0; j<adj.size(); ++j ){
		int u = adj[j].u;
		int v = adj[j].v;
		adj2[u].push_back(v);
	}
	// check for neg-weight cycles
	for( int j=0; j<adj.size(); ++j ){
		int u = adj[j].u;
		int v = adj[j].v;
		int w = adj[j].w;
		if( path[u] + w < path[v] && path[u] + w < 0 ){
			if( dfs(u) ) return false;
		}
	}
	return true;
}
int main(){
	while( cin >> n, ~n ){
		g.resize(n+1);
		adj.clear();
		for( int i=1; i<=n; ++i ){
			int r, w, x;
			cin >> g[i] >> r;
			for( int j=0; j<r; ++j ){
				cin >> x;
				adj.push_back( edge(i, x, 0) );
			}
		}
		for( int j=0; j<adj.size(); ++j ){
			adj[j].w = -g[adj[j].v];
		}
		if( BellmanFord() ) cout << "hopeless" << endl;
		else cout << "winnable" << endl;
	}
}
