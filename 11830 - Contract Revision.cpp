/**
	UVa 11830 - Contract Revision
	by Rico Tiongson
	Submitted: July 29, 2013
	Accepted 0.026s C++
	O(log(10)n) time
*/
#include<iostream>
using namespace std;
int c;
string s, ans;
int main(){
	while( cin >> c >> s, c && s!="0" ){
		ans.clear();
		c += '0';
		for( int i=0; i<s.size(); ++i ){
			if( s[i]!=c && ( s[i]!='0' || !ans.empty() ) )
			ans.push_back( s[i] );
		}
		if( ans.empty() ) cout << "0" << endl;
		else cout << ans << endl;
	}
}
