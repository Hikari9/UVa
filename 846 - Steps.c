/**
	UVa 846 - Steps
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.012s ANSI C
	O(1) time
*/
#include<stdio.h>
#include<math.h>
int n;
long long a, b, i;
int main(){
	scanf("%d", &n);
	while( n-- ){
		scanf("%lld %lld", &a, &b );
		b -=a;
		if( !b ) puts("0");
		else
		printf("%lld\n", (long long)sqrt(b*4-1));
	}
}