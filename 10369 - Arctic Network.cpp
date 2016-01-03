/**
	UVa 10369 - Arctic Network
	by Rico Tiongson
	Submitted: June 29, 2013
	Accepted 0.032s C++
	O(nlogn) time
*/
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct edge{
	int i, j, w;
	edge() {}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator< ( const edge& _ )const{ return _.w < w; }
};
int n, s, p, i, j, X[501], Y[501], f[501], dx, dy, mx;
priority_queue<edge> pq;
int find( int x ){
	return f[x]==-1 ? x : f[x] = find( f[x] );
}
int dist( int x, int y ){
	dx = X[x] - X[y];
	dy = Y[x] - Y[y];
	return (dx*dx + dy*dy);
}
double kruskals(){
	memset( f, -1, p*4 );
	mx = 0;
	while( !pq.empty() ){
		i = find( pq.top().i );
		j = find( pq.top().j );
		if( i!=j ){
			f[i] = j;
			mx = pq.top().w;
			if( --p == s ) return sqrt(mx);
		}
		pq.pop();
	}
	return sqrt(mx);
}
int main(){
	scanf("%d",&n);
	while( n ){
		scanf("%d %d", &s, &p );
		pq = priority_queue<edge>();
		for( i=0; i<p; ++i ){
			scanf( "%d %d", X+i, Y+i );
			for( j=0; j<i; ++j )
				pq.push( edge( i, j, dist( i, j ) ) );
		}
		printf( "%.2lf\n", kruskals() );
		--n;
	}
}
