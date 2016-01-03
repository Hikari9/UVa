/**
	UVa 10622 - Perfect P-th Powers
	by Rico Tiongson
	Submitted: July 26, 2013
	Accepted 0.015s C++
	O(sqrtn) time
*/
#include<cstdio>
#include<cmath>
using namespace std;
int i, j, lim;
long long x, y;
double qrt;
int main(){
	while( scanf("%lld",&x)==1 ){
		if( !x ) return 0;
		if( x<0LL ){
			for( i=-2, lim=-(sqrt(-x)+1); i>lim; --i ){
				y = i;
				for( j=2; y>x; ++j ){
					y *= i;
				}
				--j;
				if( y==x ) goto found;
			}
		}
		else for( i=2, lim=sqrt(x)+1; i<lim; ++i ){
			y = i;
			for( j=2; y<x; ++j ){
				y *= i;
			}
			--j;
			if( y==x ) goto found;
		}
		puts("1");
		continue;
		found: printf("%d\n",j);
	}
}
