/**
	UVa 11833 - Route Change
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.032s C++
	O(mlogn) time
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct edge{
	int i;
	unsigned w;
	edge() {}
	edge( int I, unsigned W ): i(I), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
} E;
int n, m, c, k, a, b, i;
unsigned path[251], adj[251][251], w;
bool v[251];
unsigned dijkstra(){
	priority_queue<edge> pq;
	memset( v, 0, sizeof v );
	memset( path, -1, sizeof path );
	path[k] = 0;
	pq.push( edge(k,0) );
	--c;
	while( !pq.empty() ){
		E = pq.top();
		pq.pop();
		if( v[E.i] ) continue;
		v[E.i] = true;
		// destination
		if( E.i==c ) return E.w;
		if( E.i<c ){
			// service route
			i=E.i+1;
			if( !v[i] && adj[E.i][i]!=-1 && adj[E.i][i] + E.w < path[i] ){
				path[i] = adj[E.i][i] + E.w;
				pq.push( edge(i,path[i]) );
			}
		}
		else{
			// not service route, can go anywhere
			for( i=0; i<n; ++i ){
				if( !v[i] && adj[E.i][i]!=-1 && adj[E.i][i] + E.w < path[i] ){
					path[i] = adj[E.i][i] + E.w;
					pq.push( edge(i,path[i]) );
				}
			}
		}
	}
	return 0;
}
int main(){
	while( scanf( "%d %d %d %d", &n, &m, &c, &k )==4, n||m||c||k ){
		memset( adj, -1, sizeof adj );
		while( m-- ){
			scanf( "%d %d %u", &a, &b, &w );
			adj[a][b] = adj[b][a] = min(adj[a][b],w);
		}
		printf( "%u\n", dijkstra() );
	}
}
