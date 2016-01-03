/**
	UVa 12047 - Highest Paid Toll
	by Rico Tiongson
	Submitted: July 4, 2013
	Accepted 0.175s C++
	O( 2nlogn + m ) time
*/
#include<vector>
#include<queue>
#include<cstdio>
#define INF 2147483647
using namespace std;
struct edge1{
	int u, v, w;
	edge1(){}
	edge1( int U, int V, int W ): u(U), v(V), w(W) {}
	void in(){
		scanf("%d %d %d", &u, &v, &w);
	}
} E[100001];
struct edge2{
	int next, w;
	edge2() {}
	edge2( int N, int W ): next(N), w(W) {}
	// for heap
	bool operator<( const edge2& _ )const{
		return w > _.w;
	}
};
struct node{
	int path;
	bool v;
	vector<edge2> fr;
	void clear(){
		fr.clear();
	}
	void reset(){
		v = false;
		path = INF;
	}
} S[10001], T[10001];
int tt, n, m, s, t, p, i, ans;
void dijkstra( node* V, int start ){
	for( i=1; i<=n; ++i ){
		V[i].reset();
	}
	V[ start ].path = 0;
	priority_queue< edge2 > pq;
	pq.push( edge2( start, 0 ) );
	while( !pq.empty() ){
		node& nr = V[ pq.top().next ];
		if( !nr.v ){
			nr.v = true;
			for( i=0; i<nr.fr.size(); ++i ){
				edge2& er = nr.fr[i];
				if( !V[ er.next ].v && V[ er.next ].path > nr.path + er.w ){
					V[ er.next ].path = nr.path + er.w;
					pq.push( edge2( er.next, V[ er.next ].path ) );
				}
			}
		}
		pq.pop();
	}
}
int main(){
	scanf("%d", &tt);
	while( tt-- ){
		scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
		for( i=1; i<=n; ++i ){
			S[i].clear();
			T[i].clear();
		}
		for( i=0; m; --m){
			E[i].in();
			if( E[i].w<=p ){
				S[ E[i].u ].fr.push_back( edge2( E[i].v, E[i].w ) );
				T[ E[i].v ].fr.push_back( edge2( E[i].u, E[i].w ) );
				++i;
			}
		}
		m = i;
		// dijkstra
		ans = -1;
		dijkstra( S, s );
		dijkstra( T, t );
		for( i=0; i<m; ++i ){
			if( S[ E[i].u ].path!=INF && T[ E[i].v ].path!=INF ){
				if( S[ E[i].u ].path + E[i].w + T[ E[i].v ].path <=p ){
					if( E[i].w > ans ) ans = E[i].w;
				}
			}
		}
		printf("%d\n", ans );
	}
}
