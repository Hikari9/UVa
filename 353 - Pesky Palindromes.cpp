/**
	UVa 353 - Pesky Palindromes
	by Rico Tiongson
	Submitted: September 11, 2013
	Accepted 0.019s C++
	O(n^2logn) time
*/
#include<cstdio>
#include<cstring>
#include<set>
#include<string>
using namespace std;
set<string> ans;
char c[85];
int dp[85][85];
bool dfs( int i, int j ){
	if( i==j ){
		ans.insert( string(c+i,c+i+1) );
		return true;
	}
	if( i>j ){
		return true;
	}
	if( dp[i][j]!=-1 ){
		return dp[i][j];
	}
	if( c[i]==c[j] ){
		dp[i][j] = dfs( i+1, j-1 );
		if( dp[i][j] ){
			ans.insert( string( c+i, c+j+1 ) );
		}
	}
	else{
		dp[i][j] = false;
	}
	dfs(i+1,j);
	dfs(i,j-1);
	return dp[i][j];
}
int main(){
	while( gets(c) ){
		ans.clear();
		memset( dp, -1, sizeof dp );
		dfs( 0, strlen(c)-1 );
		printf( "The string '%s' contains %d palindromes.\n", c, ans.size() );
		// for( set<string>::iterator it=ans.begin(); it!=ans.end(); ++it ){
			// printf( "%s\n", it->c_str() );
		// }
	}
}
