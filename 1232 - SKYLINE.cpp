/**
	UVa 1232 - SKYLINE
	by Rico Tiongson
	Submitted: October 20, 2013
	Accepted 0.369s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MX 131073
#define INF 2147483647
using namespace std;

int t, n;
int l, r, h;
int st[MX<<2], dt[MX<<2], overlaps;

void renew( int p ){
	st[p] = max( st[p], dt[p] );
	int next = p << 1;
	dt[next] = max( dt[next], dt[p] );
	dt[next+1] = max( dt[next+1], dt[p] );
	dt[p] = -1;
}

void modify( int p, int L, int R ){
	if( r < L || l > R ) return;
	int M = (L + R) >> 1;
	int next = p << 1;
	if( l <= L && R <= r ){
		dt[p] = max( dt[p], h );
		if( max( dt[p], st[p] ) <= h ){
			renew( p );
			if( L == R ){
				++overlaps;
				return;
			}
			modify( next, L, M );
			modify( next+1, M+1, R );
		}
		return;
	}
	renew( p );
	modify( next, L, M );
	modify( next+1, M+1, R );
	st[p] = min( max( st[next], dt[next] ), max( st[next+1], dt[next+1] ) );
}

int main(){
	scanf( "%d", &t );
	while(t--){
		scanf( "%d", &n );
		overlaps = 0;
		memset( st, 0, sizeof st );
		memset( dt, -1, sizeof dt );
		for( int i=0; i<n; ++i ){
			scanf( "%d %d %d", &l, &r, &h );
			--r;
			modify( 1, 1, MX-1 );
		}
		printf( "%d\n", overlaps );
	}
}
