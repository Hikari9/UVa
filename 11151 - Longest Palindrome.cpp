/**
	UVa 11151 - Longest Palindrome
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.225s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int n, i, mx;
int dp[1005][1005];
string s;
int lcs( int I, int J ){
	if( I>J ) return 0;
	if( I==J ) return 1;
	if( dp[I][J]!=-1 ) return dp[I][J];
	dp[I][J] = max( lcs(I+1,J), lcs(I,J-1) );
	if( s[I]==s[J] ) dp[I][J] = max( dp[I][J], lcs(I+1,J-1)+2 );
	return dp[I][J];
}
int main(){
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin,s);
		memset( dp, -1, sizeof dp );
		cout << lcs( 0, s.size()-1 ) << endl;
	}
}
