/**
	UVa 11687 - Digits
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.042s ANSI C
	O(log10log10n) time
*/
#include<stdio.h>
#include<string.h>
int x, x1, c;
char buf[1000005];
int main(){
	redo:
	gets( buf );
	if( buf[0]=='E' ) return 0;
	if( buf[0]=='1' && !buf[1] ){
		puts("1");
		goto redo;
	}
	c = 1;
	x = strlen( buf );
	while( 1 ){
		sprintf( buf, "%d", x );
		x1 = strlen( buf );
		++c;
		if( x==x1 ) break;
		x = x1;
	}
	printf("%d\n", c);
	goto redo;
}
