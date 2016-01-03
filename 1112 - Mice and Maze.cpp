/**
	UVa 1112 - Mice and Maze
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define sz 105
#define INF 2139062143LL
using namespace std;
typedef long long lag;
int path[sz], adj[sz][sz];
bool v[sz];
int T, n, e, m, i, a, b;
lag t, c;
struct edge{
	int i;
	lag w;
	edge() {}
	edge( int I, lag W ): i(I), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
};
int dijkstra(){
	path[e] = 0;
	priority_queue<edge> pq;
	pq.push( edge( e, 0 ) );
	while( !pq.empty() ){
		edge E = pq.top();
		pq.pop();
		if( !v[E.i] ){
			// cout << E.i << endl;
			v[E.i] = true;
			for( i=1; i<=n; ++i ){
				if( !v[i] && adj[E.i][i]!=INF &&  adj[E.i][i]+E.w < path[i] ){
					path[i]  = adj[E.i][i] + E.w;
					pq.push( edge(i,path[i]) );
				}
			}
		}
		
	}
	a = 0;
	for( i=1; i<=n; ++i ){
		if( path[i] <= t ){
			++a;
		}
	}
	return a;
}
int main(){
	// memset( path, 127, sizeof path );
	// cout << *path << endl;
	cin >> T;
	while( T ){
		cin >> n >> e >> t >> m;
		memset( path, 127, sizeof path );
		memset( adj, 127, sizeof adj );
		memset( v, 0, sizeof v );
		for( i=0; i<m; ++i ){
			cin >> b >> a >> c;
			if( adj[a][b] > c ) adj[a][b] = c; // ensure quickest path
		}
		cout << dijkstra() << endl;
		if( --T ) cout << endl;
	}
}
