/**
	UVa 10842 - Traffic Flow
	by Rico Tiongson
	Submitted: July 7, 2013
	Accepted 0.135s C++
	O( mlogn ) time
*/
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 2147483647
using namespace std;
struct edge{
	int i, j, w;
	edge(){}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator< ( const edge& _ )const{
		return w < _.w;
	}
};
int t, n, m, a, b, c, r=0, f[101];
int find( int x ){
	return f[x]==-1 ? x : f[x] = find( f[x] );
}
priority_queue<edge> pq;
int kruskals(){
	memset( f, -1, sizeof(f) );
	c = INF;
	while( !pq.empty() ){
		a = find( pq.top().i );
		b = find( pq.top().j );
		if( a != b ){
			f[a] = b;
			c = min( c, pq.top().w );
			if( --n<2 ) break;
		}
		pq.pop();
	}
	return c;
}
int main(){
	scanf("%d",&t);
	for( r=1; r<=t; ++r ){
		scanf("%d %d",&n,&m);
		pq = priority_queue<edge>();
		while( m-- ){
			scanf("%d %d %d",&a,&b,&c);
			pq.push( edge(a,b,c) );
		}
		printf("Case #%d: %d\n",r,kruskals());
	}
}
