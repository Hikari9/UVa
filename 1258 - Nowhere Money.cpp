/**
	UVa 1258 - Nowhere Money
	by Rico Tiongson
	Submitted: September 14, 2013
	Accepted 0.022s C++
	O(logn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 92
using namespace std;
typedef unsigned long long lag;
lag fib[mx] = { 1, 1 }, l[mx];
int i, lim, j;
lag x;
int main(){
	for( i=2; i<mx; ++i )
		fib[i] = fib[i-1] + fib[i-2];
	while( scanf("%llu",&x)==1 ){
		printf("%llu\n",x);
		j = i = 0;
		lim = mx;
		while(x){
			i = upper_bound( fib, fib + lim, x ) - fib - 1;
			// if(j) putchar(' ');
			printf( "%d ", i );
			x -= fib[i];
			l[j++] = fib[i];
			lim = i ? i-1 : 0;
		}
		putchar('\n');
		if(j){
			// printf( "%llu", l[0] );
			for( i=0; i<j; ++i )
				printf( "%llu ", l[i] );
		}
		puts("\n");
	}
}
