/**
	UVa 11371 - Number Theory for Newbies
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
string s, t;
long long i, a, b, c;
int main(){
	while( cin >> s ){
		sort( s.begin(), s.end(), greater<char>() );
		t.assign( s.rbegin(), s.rend() );
		// get first non-leading zero
		for( i=0; i<t.size(); ++i ){
			if( t[i] != '0' ) break;
		}
		if( i!=0 ){
			char n = t[i];
			t.erase(i,1);
			t.insert( t.begin(), n );
		}
		istringstream(s) >> a;
		istringstream(t) >> b;
		cout << a << " - " << b ;
		c = a-b;
		cout << " = " << c << " = 9 * " << (c/9) << endl;
	}
}
