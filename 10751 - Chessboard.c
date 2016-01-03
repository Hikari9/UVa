/**
	UVa 10751 - Chessboard
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.009s ANSI C
	O(1) time
*/
#include<stdio.h>
#include<math.h>

int n, x;
int main(){
	double sqrt2 = sqrt(2.0) - 1.0;
	scanf( "%d", &n );
	while(n--){
		scanf( "%d", &x );
		if( x == 1 ) puts( "0.000" );
		else printf( "%.3lf\n", x * x + sqrt2 * (x-2) * (x-2) );
		if(n) putchar( '\n' );
	}
}
