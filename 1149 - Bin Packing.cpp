/**
	UVa 1149 - Bin Packing
	by Rico Tiongson
	Submitted: September 11, 2013
	Accepted 0.049s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t, n, l, L[100005], i, j, c;
int main(){
	scanf( "%d", &t );
	while( t ){
		scanf( "%d%d", &n, &l );
		for( i=0; i<n; ++i ){
			scanf( "%d", L+i );
		}
		sort( L, L+n );
		for( c=i=0, j=n-1; i<j; ++c ){
			if( L[i] + L[j] > l ){
				--j;
			}
			else{
				++i, --j;
			}
		}
		if(i==j) ++c;
		printf("%d\n",c);
		if(--t) putchar('\n');
	}
}
