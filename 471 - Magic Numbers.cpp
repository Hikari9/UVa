/**
	UVa 471 - Magic Numbers
	by Rico Tiongson
	Submitted: February 17, 2014
	Accepted 0.032s C++
	iter
*/
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
typedef long long lag;

int t;
lag n;
bool ok[10];

bool check( lag x ){
	memset( ok, 0, sizeof ok );
	while( x ){
		int d = (x % 10);
		if( ok[d] ) return false;
		ok[d] = true;
		x /= 10;
	}
	return true;
}

int main(){
	cin >> t;
	while( t-- ){
		string s;
		cin >> s;
		int zero = 0;
		while( zero < s.length() && s[zero] == '0' ) zero++;
		// cout << zero << endl;
		if( s.length() - zero <= 10 ){
			istringstream(s) >> n;
			for( lag i=1; ; ++i ){
				lag x = n*i;
				if( x > 9876543210LL ) break;
				if( !check(i) ) continue;
				if( check(x) ){
					cout << x << " / " << i << " = " << n << endl;
				}
			}
		}
		if(t) cout << endl;
	}
}
