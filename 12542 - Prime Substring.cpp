/**
	UVa 12542 - Prime Substring
	by Rico Tiongson
	Submitted: July 30, 2013
	Accepted 0.022s C++
	O( nloglogn ) pregen + O(5n) time
*/
#include<iostream>
#include<sstream>
using namespace std;
bool notpr[100000] = { true, true };
int i, j, x, mx;
string s;
int main(){
	for( j=4; j<100000; j+=2 ) notpr[j] = true;
	for( i=3; i<30; i+=2 ){
		if( !notpr[i] ){
			for( j=2*i; j<100000; j+=i ){
				notpr[j] = true;
			}
		}
	}
	while( cin >> s, s!="0" ){
		for( i=0; i<s.size(); ++i ){
			s[i]-='0';
		}
		mx = 0;
		for( i=0; i<s.size(); ++i ){
			x = 0;
			for( j=i; j<s.size() && j-i<5; ++j ){
				x *= 10;
				x += s[j];
				if( !notpr[x] ){
					mx = max( mx, x );
				}
			}
		}
		cout << mx << endl;
	}
}
