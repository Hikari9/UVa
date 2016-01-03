/**
	UVa 12345 - Dynamic len(set(a[L:R]))
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 4.732s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int n, m, i, x, y, a[50001], c;
bool vis[1000001];
char buf[3];
void insert( int _ ){
	if( vis[_] ) return;
	vis[_] = true;
	++c;
}
int main(){
	scanf( "%d %d", &n, &m );
	for( i=0; i<n; ++i ){
		scanf( "%d", a+i );
	}
	while( m-- ){
		scanf( "%s %d %d", buf, &x, &y );
		if( buf[0]=='M' ) a[x] = y;
		else{
			memset( vis, 0, sizeof vis );
			c = 0;
			while( x<y ){
				insert(a[x++]);
			}
			printf( "%d\n", c );
		}
	}
}
