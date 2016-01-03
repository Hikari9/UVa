/**
	UVa 11733 - Airports
	by Rico Tiongson
	Submitted: June 27, 2013
	Accepted 0.225s C++
	O(nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<queue>
#define mx 10001
using namespace std;
struct edge{
	int i, j, w;
	edge(){}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
};
const edge* p;
int f[mx], t, r=0, n, n2, m, A, x, y, c, sz;
bool s[mx];
priority_queue<edge> pq;
int find( int  X ){
	return f[X] ? f[X] = find( f[X] ) : X;
}
void kruskals(){
	sz = c = 0;
	memset( f+1, 0, n*4 ); // n * sizeof(int)
	n2 = n-1;
	while( !pq.empty() ){
		p = &pq.top();
		x = find( p->i );
		y = find( p->j );
		if( x!=y ){
			f[x] = y;
			c += p->w;
			if(!--n2) break;
		}
		pq.pop();
	}
	memset( s+1, 0, n );
	for( x=1; x<=n; ++x ){
		y = find( x );
		if( !s[y] ){
			s[y] = true;
			++sz;
		}
	}
	c += A*sz;
}
int main(){
	scanf( "%d", &t );
	while( r<t ){
		scanf( "%d %d %d", &n, &m, &A );
		pq = priority_queue<edge>();
		while( m ){
			scanf("%d %d %d", &x, &y, &c );
			if( c<A ) pq.push( edge(x,y,c) );
			--m;
		}
		kruskals();
		printf("Case #%d: %d %d\n", ++r, c, sz);
	}
}
