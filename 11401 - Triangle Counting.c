/**
	UVa 11401 - Triangle Counting
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.016s ANSI C
	O(1) time
*/
#include<stdio.h>
long long n;
int main(){
	scanf("%lld",&n);
	while( n>2ll ){
		n-=3ll;
		printf("%lld\n", (((n<<1)+3ll)*(n+2ll)*(n+1ll)/6ll-((n+2ll)>>1))>>2);
		scanf("%lld",&n);
	}
}
