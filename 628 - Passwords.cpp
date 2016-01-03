/**
	UVa 628 - Passwords
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 0.295s C++
	O(!) time
*/
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int n, m;
string rule, word;
vector<string> dict;
void dfs( int i, string s ){
	if( i==rule.length() ){
		cout << s << endl;
		return;
	}
	if( rule[i++]=='0' ){
		for( char c='0'; c<='9'; ++c ){
			dfs( i, s + c );
		}
	}
	else{
		for( int j=0; j<dict.size(); ++j ){
			dfs( i, s + dict[j] );
		}
	}
}
int main(){
	while( cin >> n ){
		dict.clear();
		while( n-- ){
			cin >> word;
			dict.push_back( word );
		}
		cout << "--" << endl;
		cin >> m;
		while( m-- ){
			cin >> rule;
			dfs( 0, string() );
		}
	}
}
