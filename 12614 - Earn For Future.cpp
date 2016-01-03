/**
	UVa 12614 - Earn For Future
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.016s C++
	O(n) time
*/
#include<cstdio>
using namespace std;
int x, n, j, t, tc, mx;
int main(){
	scanf( "%d", &t );
	while( tc<t ){
		scanf( "%d", &n );
		mx = 0;
		while( n-- ){
			scanf( "%d", &x );
			if( x>mx ) mx=x;
		}
		printf( "Case %d: %d\n", ++tc, mx );
	}
}
