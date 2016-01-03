/**
	UVa 12502 - Three Families
	by Rico Tiongson
	Submitted: July 2, 2013
	Accepted 0.012s ANSI C
	O(1) time
*/
#include<stdio.h>
int t, a, b, c;
int main(){
	scanf("%d",&t);
	while( t ){
		scanf("%d %d %d", &a, &b, &c );
		c *= a*2-b;
		if( c > 0 ) printf( "%d", c/(a+b) );
		else putchar('0');
		putchar('\n');
		--t;
	}
}
