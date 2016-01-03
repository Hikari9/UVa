/**
	UVa 1534 - Taekwondo
	by Rico Tiongson
	Submitted: August 5, 2013
	Accepted 0.272s C++
	O(nlogn + kn) time
*/
// #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 2139062143
using namespace std;
int a[501], b[501], n, m;
int c[501][501], val;
int t, i, j, J, k;
int Abs( int x ){ return x>=0 ? x : -x; }
int main(){
	// printf( "%d\n", c[0][0] );
	scanf( "%d\n", &t );
	while( t ){
		scanf( "%d %d\n", &n, &m );
		if( m<n ){
			for( i=0; i<n; ++i ){
				scanf( "%d.", b+i );
				b[i] = b[i]*10 + getchar()-'0';
			}
			for( i=0; i<m; ++i ){
				scanf( "%d.", a+i );
				a[i] = a[i]*10 + getchar()-'0';
			}
			j = n;
			n = m;
			m = j;
		}
		else{
			for( i=0; i<n; ++i ){
				scanf( "%d.", a+i );
				a[i] = a[i]*10 + getchar()-'0';
			}
			for( i=0; i<m; ++i ){
				scanf( "%d.", b+i );
				b[i] = b[i]*10 + getchar()-'0';
			}
		}
		sort( a, a+n );
		sort( b, b+m );
		k = m-n+1;
		memset( c, 127, sizeof c );
		for( j=0; j<k; ++j ){
			c[0][j] = Abs( a[0] - b[j] );
		}
		for( i=1; i<n; ++i ){
			val = INF;
			for( j=i, J=min(i+k,m); j<J; ++j ){
				val = min( c[i-1][j-1], val );
				c[i][j] = min( c[i][j], val+Abs( a[i]-b[j] ) );
			}
		}
		i = n-1;
		val = INF;
		for( j=i; j<m; ++j ){
			val = min( c[i][j], val );
		}
		printf( "%d.%c\n", val/10, (val%10) + '0' );
		--t;
	}
}
