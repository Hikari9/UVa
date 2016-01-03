/**
	UVa 10931 - Parity
	by Rico Tiongson
	Submitted: August 18, 2013
	Accepted 0.018s C++
	O(1) time
*/
#include<cstdio>
using namespace std;
int n, c;
void parity( int x ){
	if( x==0 ) return;
	parity(x>>1);
	if( x&1 ){
		putchar( '1' );
		++c;
	}
	else putchar( '0' );
}
int main(){
	while( scanf( "%d", &n )!=EOF, n ){
		printf( "The parity of " );
		c = 0;
		parity(n);
		printf( " is %d (mod 2).\n", c );
	}
}
