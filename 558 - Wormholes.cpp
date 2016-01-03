/**
	UVa 558 - Wormholes
	by Rico Tiongson
	Submitted: October 18, 2013
	Accepted 0.055s C++
	O(|V|.E) time
*/
#include<iostream>
#define MX 2005
#define INF 2000000000
using namespace std;
struct edge{
	int u, v, w;
	edge() {}
	edge( int U, int V, int W ): u(U), v(V), w(W) {}
};
edge E[MX];
int path[MX], prev[MX], n, m;
bool BellmanFord(){
	for( int i=0; i<n; ++i ){
		path[i] = INF;
		prev[i] = -1;
	}
	path[0] = 0;
	for( int i=1; i<n; ++i ){
		for( int j=0; j<m; ++j ){
			int u = E[j].u;
			int v = E[j].v;
			int w = E[j].w;
			if( path[u] + w < path[v] ){
				path[v] = path[u] + w;
				prev[v] = u;
			}
		}
	}
	// check for neg-weight cycles
	for( int j=0; j<m; ++j ){
		int u = E[j].u;
		int v = E[j].v;
		int w = E[j].w;
		if( path[u] + w < path[v] ){
			return false;
		}
	}
	return true;
}
int t;
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		for( int i=0; i<m; ++i )
			cin >> E[i].u >> E[i].v >> E[i].w;
		if( BellmanFord() ) cout << "not ";
		cout << "possible" << endl;
	}
}
