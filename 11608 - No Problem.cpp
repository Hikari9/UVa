/**
	UVa 11608 - No Problem
	by Rico Tiongson
	Submitted: September 28, 2013
	Accepted 0.016s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int n, i, x, tc;
int p[12];
int main(){
	while( scanf("%d",&n)==1 && n>=0 ){
		printf("Case %d:\n", ++tc);
		for( i=0; i<12; ++i ){
			scanf("%d",p+i);
		}
		for( i=0; i<12; ++i ){
			scanf("%d",&x);
			if( x <= n ){
				n -= x;
				puts("No problem! :D");
			}
			else puts("No problem. :(");
			n += p[i];
		}
	}
}
