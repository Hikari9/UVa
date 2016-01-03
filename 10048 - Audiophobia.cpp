/**
	UVa 10048 - Audiophobia
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.022s C++
	O(nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct edge{
	int i, j;
	unsigned w;
	edge() {}
	edge( int I, int J, unsigned W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
};
int f[105];
unsigned path[105][105];
int find( int x ){ return f[x]==-1 ? x : f[x]=find(f[x]); }
int n, c, s, q, a, b, w, i, j, tc;
priority_queue<edge> pq;
void kruskals(){
	memset( f, -1, sizeof f );
	memset( path, -1, sizeof path );
	for( i=1; i<=c; ++i )
		path[i][i] = 0;
	if( c<2 ) return;
	n = c;
	while( !pq.empty() ){
		a = find( pq.top().i );
		b = find( pq.top().j );
		if( a!=b ){
			for( i=1; i<=c; ++i ){
				if( find(i)==a ){
					for( j=1; j<=c; ++j ){
						if( find(j)==b ){
							path[i][j] = path[j][i] = pq.top().w;
						}
					}
				}
			}
			f[a] = b;
			if( --n == 1 ) return;
		}
		pq.pop();
	}
}
int main(){
	while( scanf( "%d %d %d", &c, &s, &q )==3, c||s||q ){
		if(tc) putchar('\n');
		pq = priority_queue<edge>();
		while( s-- ){
			scanf( "%d %d %d", &a, &b, &w );
			pq.push( edge(a,b,w) );
		}
		kruskals();
		printf( "Case #%d\n", ++tc );
		while( q-- ){
			scanf( "%d %d", &a, &b );
			if( find(a)!=find(b) ){
				puts("no path");
			}
			else{
				printf( "%d\n", path[a][b] );
			}
		}
	}
}
