/**
	UVa 11552 - Fewest Flops
	by Rico Tiongson
	Submitted: January 22, 2014
	Accepted 0.026s C++
	O(n^2) time
*/
#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#define MX 1001
using namespace std;

int n, m, k, len;
char s[MX+5];

set<char> c[MX];
int dp[MX][27];

int DP( int x, char L ){
	if( ~dp[x][L - 'a'] ) return dp[x][L - 'a'];
	if( x == m-1 ){
		return dp[x][L - 'a'] = c[x].size() - c[x].count(L);
	}
	if( c[x].size() == 1 ){
		if( c[x].count(L) ){
			return dp[x][L - 'a'] = DP( x+1, L );
		}
		else{
			return dp[x][L - 'a'] = 1 + DP( x+1, *c[x].begin() );
		}
	}
	int val = 2147483647;
	int cnt = c[x].size() - c[x].count(L);
	for( set<char>::iterator it = c[x].begin(); it != c[x].end(); ++it ){
		if( *it == L ) continue;
		val = min( val, cnt + DP( x+1, *it ) );
	}
	return dp[x][L - 'a'] = val;
}

int main(){
	scanf( "%d", &n );
	while( n-- ){
		scanf( "%d %s", &k, s );
		len = strlen(s);
		m = len / k;
		memset( dp, -1, m * (sizeof dp[0]) );
		for( int i=0; i<m; ++i ){
			c[i].clear();
		}
		for( int i=0; i<m; ++i ){
			for( int j=0; j<k; ++j ){
				c[i].insert( s[i*k +j] );
			}
		}
		cout << DP(0, 'a' + 26) << endl;
	}
}
