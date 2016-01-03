/**
	UVa 1208 - Oreon
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.016s C++
	O(nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
struct edge{
	int i, j, w;
	edge() {}
	edge( int I, int J, int W ): i(I), j(J), w(W) { if(j<i) swap(i,j); }
	bool operator<( const edge& _ )const{
		if( w==_.w ){
			if( i==_.i ){
				return _.j < j;
			}
			return _.i < i;
		}
		return _.w < w;
	}
};
int t, tc, n, f[26], i, j, w;
char buf[100001], *p;
priority_queue<edge> pq;
int find( int x ){
	return f[x]==x ? x : f[x]=find(f[x]);
}
void kruskals(){
	if( n<=1 ) return;
	while( !pq.empty() ){
		const edge& E = pq.top();
		i = find(E.i);
		j = find(E.j);
		if( i!=j ){
			f[i] = j;
			printf( "%c-%c %d\n", E.i+'A', E.j+'A', E.w );
			if( --n==1 ) return;
		}
		pq.pop();
	}
}
int main(){
	scanf( "%d", &t );
	while( tc<t ){
		scanf( "%d", &n );
		gets(buf);
		pq = priority_queue<edge>();
		for( i=0; i<n; ++i ){
			f[i] = i;
			gets(buf);
			p = strtok(buf,", ");
			for( j=0; j<n && p!=NULL; ++j ){
				w = atoi(p);
				if( w ) pq.push( edge(i,j,w) );
				p = strtok(NULL,", ");
			}
		}
		printf( "Case %d:\n", ++tc );
		kruskals();
	}
}
