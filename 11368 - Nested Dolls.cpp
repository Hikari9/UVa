/**
	UVa 11368 - Nested Dolls
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.782s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MX 20005
using namespace std;
struct doll{
	int w, h;
	// doll() {}
	inline bool operator<( const doll& _ )const{
		if( w==_.w ) return h < _.h;
		return w > _.w;
	}
} d[MX];

int t, n, i, j;
int prev[MX], next[MX], ans, x, y, h, nx;

int main(){
	scanf( "%d", &t );
	while(t--){
		scanf( "%d", &n );
		for( i=1; i<=n; ++i ){
			scanf( "%d %d", &d[i].w, &d[i].h );
		}
		sort( d+1, d+n+1 );
		for( i=0; i<=n; ++i ){
			next[i] = i+1;
			prev[i] = i-1;
		}
		ans = 0;
		next[n] = -1;
		while( next[0]!=-1 ){
			x = next[0];
			h = d[x].h;
			++ans;
			next[0] = next[x];
			if( next[x]!=-1 )
				prev[next[x]] = 0;
			while( next[x]!=-1 ){
				nx = next[x];
				if( d[nx].h < h ){
					h = d[nx].h;
					next[prev[nx]] = next[nx];
					if( next[nx]!=-1 )
						prev[next[nx]] = prev[nx];
				}
				x = nx;
			}
		}
		printf( "%d\n", ans );
	}
}
