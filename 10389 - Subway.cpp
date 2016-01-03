/**
	UVa 10389 - Subway
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.019s C++
	O(mlogn) time
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
struct edge{
	int i;
	double w;
	edge() {}
	edge( int I, double W ): i(I), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
} E;
double dist( double dx, double dy ){ return sqrt(dx*dx + dy*dy); }
int t, i, j, sz, sub;
long long x[205], y[205];
double adj[205][205], path[205];
bool vis[205];
double d;
vector<long long> v;
char buf[1000001], *p;
double dijkstra(){
	d = 0;
	memset( vis, 0, sizeof vis );
	for( i=1; i<sz; ++i ) path[i] = HUGE_VAL;
	priority_queue<edge> pq;
	path[0] = 0.0;
	pq.push( edge(0,0.0) );
	while( !pq.empty() ){
		E = pq.top();
		pq.pop();
		if( vis[E.i] ) continue;
		if( E.i==1 ) return E.w;
		vis[E.i] = true;
		for( i=0; i<sz; ++i ){
			if( !vis[i] && adj[E.i][i]!=HUGE_VAL && path[i] > E.w + adj[E.i][i] ){
				path[i] = E.w + adj[E.i][i];
				pq.push( edge(i,path[i]) );
			}
		}
	}
	return -1;
}
int main(){
	scanf( "%d", &t );
	while( t ){
		for( i=0; i<205; ++i ){
			for( j=0; j<205; ++j ){
				adj[i][j] = HUGE_VAL;
			}
		}
		scanf( "%lld %lld", x, y );
		scanf( "%lld %lld", x+1, y+1 );
		
		// adj[0][1] = adj[1][0] = dist( x[0]-x[1], y[0]-y[1] )*6.0;
		sz = 2;
		sub = 2;
		if(cin.getline(buf,1000000)){
			v.clear();
			while( cin.getline(buf,1000000), buf[0] ){
				p = strtok(buf," ");
				while( p!=NULL ){
					v.push_back(0);
					sscanf( p, "%lld", &v.back() );
					p = strtok(NULL," ");
				}
			}
			
			for( i=1; i<v.size(); i+=2, ++sz ){
				if( v[i]==-1 && v[i-1]==-1 ){
					sub = sz;
					--sz;
					continue;
				}
				x[sz] = v[i-1];
				y[sz] = v[i];
				if( sub!=sz ){
					j = sz-1;
					// take subway
					adj[sz][j] = adj[j][sz] = dist( x[sz]-x[j], y[sz]-y[j] )*1.5;
				}
			}
		}
		for( i=0; i<sz; ++i ){
			adj[i][i] = 0.0;
			for( j=0; j<i; ++j ){
				adj[i][j] = adj[j][i] = min(adj[i][j],dist(x[i]-x[j],y[i]-y[j])*6.0);
			}
		}
		printf( "%.0lf\n", dijkstra()/1000.0 );
		if(--t) putchar( '\n' );
	}
}
