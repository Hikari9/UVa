/**
	UVa 11313 - Gourmet Games
	by Rico Tiongson
	Submitted: June 29, 2013
	Accepted 0.035s ANSI C
	O(?) time
*/
#include<stdio.h>
int t, n, m, i;
int main(){
	scanf("%d",&t);
	while( t ){
		scanf("%d %d",&n,&m);
		for( i=1; ; ++i ){
			n = n-m+1;
			if( n<m ){
				if( n!=1 )
					puts("cannot do this");
				else
					printf("%d\n",i);
				break;
			}
		}
		--t;
	}
}
