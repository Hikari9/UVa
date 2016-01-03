/**
	UVa 10656 - Maximum Sum(II)
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.028s ANSI C
	O(n) time
*/
#include<stdio.h>
int f, n, x;
int main(){
	scanf("%d",&n);
	while( n ){
		getchar();
		f = 0;
		do{
			scanf("%d",&x);
			getchar();
			if( x ){
				if( f ) putchar(' ');
				else f = 1;
				printf("%d",x);
			}
		} while( --n );
		if( !f ) putchar('0');
		putchar('\n');
		scanf("%d",&n);
	}
}
