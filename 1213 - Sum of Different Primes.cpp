/**
	UVa 1213 - Sum of Different Primes
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 0.119s C++
	O(dp) time
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MX 1121
#define INF -1
using namespace std;
bool notprime[MX];
vector<int> pr;
int a, b;
int dp[MX][15][187];
// num, ways, prime id
int dfs( int i, int j, int k ){
	if( i==0 && j==0 ) return 1;
	if( i<0 || j==0 || k>186 ) return 0;
	if( dp[i][j][k]!=INF ) return dp[i][j][k];
	// get count if not used/used
	return dp[i][j][k] = dfs(i,j,k+1) + dfs(i-pr[k],j-1,k+1);
}
int main(){
	// sieve
	pr.push_back(2);
	for( a=3; a<MX; a+=2 ){
		if( !notprime[a] ){
			pr.push_back(a);
			for( b=a*a; b<MX; b+=a )
				notprime[b] = true;
		}
	}
	memset( dp, INF, sizeof dp );
	while( cin >> a >> b, a||b ){
		cout << dfs(a,b,0) << endl;
	}
}
