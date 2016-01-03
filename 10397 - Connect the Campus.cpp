/**
	UVa 10397 - Connect the Campus
	by Rico Tiongson
	Submitted: july 11, 2013
	Accepted 0.062s C++
	O(n+mlogm) time
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
struct edge{
	int i, j, w;
	edge(){}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ )const{ return _.w < w; }
};
int n, m, f[751], i, j, x[751], y[751], dx, dy;
double ans;
priority_queue<edge> pq;
int find( int x ){
	return f[x]==x ? x : f[x]=find(f[x]);
}
int dist(){
	dx = x[i]-x[j];
	dy = y[i]-y[j];
	return dx*dx + dy*dy;
}
double kruskals(){
	if( n<2 ) return 0.;
	ans = 0.;
	while( !pq.empty() ){
		i = find( pq.top().i );
		j = find( pq.top().j );
		if( i!=j ){
			f[i] = j;
			ans += sqrt( pq.top().w );
			if( --n==1 ) return ans;
		}
		pq.pop();
	}
	return ans;
}
int main(){
	while( scanf("%d",&n)==1 ){
		pq = priority_queue<edge>();
		for( i=1; i<=n; ++i ){
			scanf("%d %d", x+i, y+i);
			f[i] = i;
			for( j=1; j<i; ++j ){
				pq.push( edge( i, j, dist() ) );
			}
		}
		scanf("%d", &m);
		while( m-- ){
			scanf("%d %d", &i, &j);
			if( n>1 ){
				i = find(i);
				j = find(j);
				if( i!=j ){
					f[i] = j;
					--n;
				}
			}
		}
		printf("%.2lf\n",kruskals());
	}
}
