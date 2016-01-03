/**
	ACM 3225 - Circular Sequence
	by Rico Tiongson
	Submitted: July 24, 2013
	Accepted 0.009s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int t, i, len;
string s, str, mn;
int main(){
	cin >> t;
	while( t-- ){
		cin >> s;
		mn = s;
		len = s.size();
		s.append(s);
		for( i=1; i<len; ++i ){
			str = s.substr( i, len );
			if( str < mn ) mn = str;
		}
		cout << mn << endl;
	}
}
