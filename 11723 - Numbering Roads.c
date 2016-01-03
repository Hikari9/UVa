/**
	UVa 11723 - Numbering Roads
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.019s ANSI C
	O(1) time
*/
#include<stdio.h>
int n, r, t=0;
int main(){
	scanf( "%d %d", &n, &r );
	while( n || r ){
		printf("Case %d: ",++t);
		n = n/r - (n%r==0) ;
		if( n>26 ) puts("impossible");
		else printf("%d\n",n);
		scanf( "%d %d", &n, &r );
	}
}
