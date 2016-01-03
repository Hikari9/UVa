/**
	UVa 11877 - The Coco-Cola Store
	by Rico Tiongson
	Submitted: July 2, 2013
	Accepted 0.009s ANSI C
	O(1) time
*/
#include<stdio.h>
int x;
int main(){
	while( 1 ){
		scanf("%d",&x);
		if( !x ) return 0;
		printf("%d\n",x/2);
	}
}
