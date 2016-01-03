/**
	UVa 10610 - Gopher and Hawks
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.035s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct point{
	double x, y;
	point() {}
	point( double X, double Y ): x(X), y(Y) {}
};
struct edge{
	int i, d;
	edge() {}
	edge( int I, int D ): i(I), d(D) {}
} E;
double dist2( double dx, double dy ){
	return dx*dx + dy*dy;
}
char buf[105], *p;
int v, m, sz, i, j, ans;
point a[1005];
bool vis[1005], adj[1005][1005];
double x, d;
int bfs(){
	d = v*m*60;
	d *= d;
	memset( adj, 0, sizeof adj );
	for( i=1; i<sz; ++i ){
		for( j=0; j<i; ++j ){
			x = dist2( a[i].x-a[j].x, a[i].y-a[j].y );
			if( x<=d ){
				adj[i][j] = adj[j][i] = true;
			}
		}
	}
	memset( vis, 0, sizeof vis );
	queue<edge> q;
	// start node 0
	q.push( edge(0,0) );
	vis[0] = true;
	while( !q.empty() ){
		E = q.front();
		++E.d;
		q.pop();
		for( i=1; i<sz; ++i ){
			if( !vis[i] && adj[E.i][i] ){
				vis[i] = true;
				if( i==1 ) return E.d-1;
				q.push( edge(i,E.d) );
			}
		}
	}
	return -1;
}
int main(){
	while( scanf("%d %d",&v,&m)==2 , v||m ){
		getchar();
		gets(buf);
		sscanf( buf, "%lf %lf", &a[0].x, &a[0].y );
		gets(buf);
		sscanf( buf, "%lf %lf", &a[1].x, &a[1].y );
		for( sz=2; gets(buf); ++sz ){
			if( sscanf( buf, "%lf %lf", &a[sz].x, &a[sz].y ) !=2 ) break;
		}
		ans = bfs();
		if( ans==-1 ){
			puts("No.");
		}
		else{
			printf( "Yes, visiting %d other holes.\n", ans );
		}
	}
}
