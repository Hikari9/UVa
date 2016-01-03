/**
	UVa 10453 - Make Palindrome
	by Rico Tiongson
	Submitted: January 21, 2014
	Accepted 2.952s C++
	O(n^2) time
*/
#include <iostream>
#include <cstring>
#define MX 1001
#define INS 0
#define DEL 1
#define RET 2
using namespace std;

string s;
int dp[MX][MX], prev[MX][MX];

int DP( int i, int j ){
	if( i > j ) return 0;
	if( ~dp[i][j] ) return dp[i][j];
	int val = 2147483647, temp;
	if( s[i] == s[j] ){
		val = DP( i+1, j-1 );
		prev[i][j] = RET;
	}
	// insert top
	temp = DP( i+1, j ) + 1;
	if( temp < val ){
		val = temp;
		prev[i][j] = INS;
	}
	// delete bottom
	temp = DP( i, j-1 ) + 1;
	if( temp < val ){
		val = temp;
		prev[i][j] = DEL;
	}
	return dp[i][j] = val;
}

int main(){
	while( cin >> s ){
		memset( dp, -1, sizeof dp );
		memset( prev, -1, sizeof prev );
		int add = DP(0, s.length() - 1);
		cout << add << " ";
		string out;
		int i = 0, j = s.length()-1;
		while( prev[i][j] != -1 ){
			switch( prev[i][j] ){
				case INS:
					out.push_back( s[i++] );
					break;
				case DEL:
					out.push_back( s[j--] );
					break;
				case RET:
					out.push_back( s[i] );
					i++, j--;
			}
		}
		out.append( string( out.rbegin(), out.rend() ) );
		while( out.length() > s.length() + add ){
			out.erase( out.size() / 2, 1 );
		}
		cout << out << endl;
	}
}
