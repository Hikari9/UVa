/**
	UVa 12650 - Dangerous Dive
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.013s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int n, r, i, x;
bool b[10005], f;
int main(){
	while( scanf( "%d %d", &n, &r )==2 ){
		memset( b+1, 1, n );
		for( i=0; i<r; ++i ){
			scanf( "%d", &x );
			b[x] = 0;
		}
		f = 0;
		for( i=1; i<=n; ++i ){
			if( b[i] ){
				f = 1;
				printf( "%d ", i );
			}
		}
		if(!f) putchar('*');
		putchar('\n');
	}
}
