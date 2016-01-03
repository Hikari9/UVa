/**
	UVa 10819 - Trouble of 13-Dots
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 0.368s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int m, n, i, j, mx;
int dp[101][10201], u[101], v[101];
int main(){
	while( cin >> m >> n ){
		if( !n ){
			cout << '0' << endl;
			continue;
		}
		for( i=0; i<n; ++i ){
			cin >> u[i] >> v[i];
		}
		memset( dp, 0, sizeof dp );
		dp[0][u[0]] = v[0];
		for( i=1; i<n; ++i ){
			for( j=0; j<10201; ++j ){
				dp[i][j] = dp[i-1][j];
				if( j>=u[i] && ( dp[i-1][j-u[i]]!=0 || j==u[i] ) ){
					dp[i][j] = max( dp[i][j], dp[i-1][j-u[i]]+v[i] );
				}
			}
		}
		mx = 0;
		for( i=0; i<=m; ++i ){
			mx = max( dp[n-1][i], mx );
		}
		for( i=2001; i-200<=m && i<10201; ++i ){
			mx = max( dp[n-1][i], mx );
		}
		cout << mx << endl;
	}
}
