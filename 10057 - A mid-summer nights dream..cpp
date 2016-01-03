/**
	UVa 134 - A mid-summer night's dream.
	by Rico Tiongson
	Submitted: August 25, 2013
	Accepted 0.249s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned short x[1000005];
int cnt[65536];
int n, i, sz, sum, ans;
int main(){
	while( scanf( "%d", &n )==1 ){
		memset( cnt, 0, sizeof cnt );
		for( i=0; i<n; ++i ){
			scanf( "%hu", x+i );
			++cnt[x[i]];
		}
		sort(x,x+n);
		ans = 1;
		if( n&1 ){
			sz = n>>1;
			sum = cnt[x[sz]];
		}
		else{
			sz = (n>>1) - 1;
			sum = cnt[x[sz]];
			if( x[sz+1]!=x[sz] ){
				sum += cnt[x[sz+1]];
				ans += x[sz+1] - x[sz];
			}
			
		}
		printf( "%d %d %d\n", x[sz], sum, ans );
	}
}
