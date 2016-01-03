/**
	UVa 11003 - Boxes
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.038s C++
	O(n^2) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int dp[6005];
int w[1005], k[1005];
int main(){
	while( scanf( "%d", &n ) == 1 && n ){
		for( int i=0; i<n; ++i ){
			scanf( "%d %d", w+i, k+i );
		}
		memset( dp, 0, sizeof dp );
		for( int i=n-1; i>=0; --i ){
			for( int j=k[i]; j>=0; --j ){
				if( dp[j] > 0 ){
					dp[ j+w[i] ] = max( dp[ j+w[i] ], dp[j] + 1 );
				}
			}
			dp[ w[i] ] = max( dp[ w[i] ], 1 );
		}
		printf( "%d\n", *max_element( dp, dp+6005 ) );
	}
}
