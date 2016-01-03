/**
	UVa 10963 - The Swallowing Ground
	by Rico Tiongson
	Submitted: June 16, 2013
	Accepted 0.009s C++
	O(n) time
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int t, flag, n, a, b;
int main(){
	scanf("%d",&t);
	while( t ){
		scanf("%d",&n);
		flag = 0;
		if( n ){
			scanf("%d %d",&a,&b);
			flag = abs(a-b);
			while( --n ){
				scanf("%d %d",&a,&b);
				if( flag!=-1 && flag!=abs(a-b) ) flag=-1;
			}
		}
		if( flag==-1 ) puts("no");
		else puts("yes");
		if(--t) putchar('\n');
	}
}
