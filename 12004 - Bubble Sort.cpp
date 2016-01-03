/**
	UVa 12004 - Bubble Sort
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.015s C++
	O(1) time
*/
#include<stdio.h>
int t, r=0;
long long n;
int main(){
	scanf("%d",&t);
	while( r<t ){
		scanf("%lld",&n);
		n*=(n-1);
		printf("Case %d: ", ++r);
		switch( n%4 ){
			case 0:
				printf("%lld\n", n>>2);
				break;
			case 2:
				printf("%lld/2\n",n>>1);
		}
	}
}
