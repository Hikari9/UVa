/**
	UVa 10147 - Highways
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.198s C++
	O(nlogn) time
*/
// #include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
template<class Type>
struct point{
	Type x, y;
	point() {}
	point( Type X, Type Y ): x(X), y(Y) {}
};
template<class Type>
Type dist2( const point<Type>& a, const point<Type>& b ){
	Type dx = a.x-b.x;
	Type dy = a.y-b.y;
	return dx*dx + dy*dy;
}
struct edge{
	int i, j, w;
	edge() {}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ ) const{
		return _.w < w;
	}
};

int t, n, n2, m, f[755], i, j, a, b;
point<int> p[755];
int find( int x ){ return f[x]==x ? x : f[x]=find(f[x]); }

bool kruskals(){
	if( n2<=1 ) return false;
	priority_queue<edge> pq;
	for( i=1; i<n; ++i ){
		for( j=i+1; j<=n; ++j ){
			if( find(i)!=find(j) ){
				pq.push( edge(i,j,dist2(p[i],p[j])) );
			}
		}
	}
	while( !pq.empty() ){
		const edge& e = pq.top();
		a = find( e.i );
		b = find( e.j );
		if( a!=b ){
			f[a] = b;
			printf( "%d %d\n", e.i, e.j );
			if( --n2==1 ) return true;
		}
		pq.pop();
	}
	return false;
}

int main(){
	scanf( "%d", &t );
	while( t ){
		scanf( "%d", &n );
		for( i=1; i<=n; ++i ){
			scanf( "%d %d", &p[i].x, &p[i].y );
			f[i] = i;
		}
		scanf( "%d", &m );
		n2 = n;
		while( m-- ){
			scanf( "%d %d", &a, &b );
			a = find(a);
			b = find(b);
			if( a!=b ){
				--n2;
				f[a] = b;
			}
		}
		if( !kruskals() ){
			puts( "No new highways need" );
		}
		if( --t ) putchar('\n');
	}
}
