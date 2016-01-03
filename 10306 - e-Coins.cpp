/**
	UVa 10306 - e-Coins
	by Rico Tiongson
	Submitted: January 23, 2014
	Accepted 0.109s C++
	O(n^3) time
*/
#include <iostream>
#include <cstring>
#include <cmath>
#define INF 2147483647
using namespace std;

int t, n, S;
int m[41][2];
int dp[41][301][301];

int DP( int i, int j, int k ){
	if( ~dp[i][j][k] ) return dp[i][j][k];
	int val = INF;
	if( i != 0 ) val = DP( i-1, j, k );
	int dx = j - m[i][0];
	int dy = k - m[i][1];
	if( dx >= 0 && dy >= 0 ){
		int temp = DP( i, dx, dy );
		if( temp != INF )
			val = min( val, temp + 1 );
	}
	return dp[i][j][k] = val;
}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> S;
		for( int i=0; i<n; ++i ){
			cin >> m[i][0] >> m[i][1];
		}
		memset( dp, -1, sizeof dp );
		dp[0][0][0] = 0;
		int mn = INF;
		for( int i=0; i<=S; ++i ){
			int J = S*S - i*i;
			int j = (int)(sqrt(J) + 1e-7);
			if( j*j == J ){
				// cout << i << " " << j << " " << DP(n-1, i, j) << endl;
				mn = min( mn, DP(n-1, i, j) );
			}
		}
		if( mn == INF ) cout << "not possible" << endl;
		else cout << mn << endl;
	}
}
