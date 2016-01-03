/**
	UVa 10616 - Divisible Group Sums
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.129s C++
	O(n^4) time
*/
#include<iostream>
#include<cstring>
#define K 11
#define MOD 21
using namespace std;
int n, q, d, m, qd, qm, tc;
long long a[201];
int dp[MOD][MOD][K][201];
int memo[MOD][K];
int main(){
	while( cin >> n >> q, n || q ){
		for( int i=1; i<=n; ++i ){
			cin >> a[i];
		}
		memset( dp, 0, sizeof dp );
		for( int i=1; i<=n; ++i ){
			for( int j=1; j<MOD; ++j ){
				dp[j][((a[i]%j)+j)%j][1][i] = 1;
			}
		}
		
		for( int i=1; i<MOD; ++i ){
			for( int k=1; k<K; ++k ){ // number of chosen
				for( int l=1; l<=n; ++l ){
					for( int j=0; j<i; ++j ){
						int x = ( i + j - a[l] % i ) % i;
						dp[i][j][k][l] += dp[i][x][k-1][l-1];
						dp[i][j][k][l] += dp[i][j][k][l-1];
					}
				}
			}
		}
		
		memset( memo, 0, sizeof memo );
		for( int i=0; i<MOD; ++i ){
			for( int k=1; k<K; ++k ){
				memo[i][k] += dp[i][0][k][n];
			}
		}
		cout << "SET " << ++ tc << ":\n";
		for( int i=1; i<=q; ++i ){
			cin >> qd >> qm;
			// cout << qd << " " << qm << endl;
			cout << "QUERY " << i << ": ";
			cout << memo[qd][qm] << endl;
		}
	}
}
