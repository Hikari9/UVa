/**
	UVa 10099 - The Tourist Guide
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.018s C++
	O(logn) time
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct edge{
	int i, j, w;
	edge(){}
	edge( int a, int b, int c ): i(a), j(b), w(c) {}
	bool operator<( const edge& rhs )const{ return w < rhs.w; }
};
int f[102], n, m, x, y, d, r=0;
int find( int x ){ return f[x]==x ? x : f[x] = find( f[x] ); }
priority_queue<edge> pq;
int kruskals(){
	for( int i=1; i<n; ++i ) f[i] = i;
	f[n] = n;
	while( !pq.empty() ){
		n = find(pq.top().i);
		m = find(pq.top().j);
		if(n!=m){
			f[n] = m;
			if(find(x)==find(y)){
				return (d/pq.top().w)+ (d%pq.top().w!=0);
			}
		}
		pq.pop();
	}
	return -1;
}
int main(){
	scanf( "%d %d", &n, &m );
	while( n || m ){
		pq = priority_queue<edge>();
		while( m ){
			scanf("%d %d %d",&x,&y,&d);
			pq.push( edge(x,y,d-1) );
			--m;
		}
		scanf("%d %d %d",&x,&y,&d);
		printf( "Scenario #%d\nMinimum Number of Trips = %d\n\n", ++r, kruskals() );
		scanf( "%d %d", &n, &m );
	}
}
