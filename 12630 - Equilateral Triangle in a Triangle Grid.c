/**
	UVa 12630 - Equilateral Triangle in a Triangle Grid
	by Rico Tiongson
	Submitted: May 26, 2013
	Accepted 0.012s C
	O(1) time
*/
#include<stdio.h>
int n;
int main(){
	scanf("%d",&n);
	while(n){
		printf("%d\n",(n+2)*(n+1)*n*(n-1)/24);
		scanf("%d",&n);
	}
}
