/**
	UVa 10162 - Last Digit
	by Rico Tiongson
	Submitted: October 12, 2013
	Accepted 0.019s C++
	O(n) pregen + O(1) time
*/
#include<iostream>
#include<sstream>
#define MX 201
using namespace std;
int a[MX], x;
int power(int b, int e){
	if( e==0 ) return 1;
	int half = power(b, e>>1);
	half = (half*half)%10;
	if( e&1 ) return (half*b)%10;
	return half;
}
string s;
int main(){
	a[0] = 0;
	a[1] = 1;
	for( int i=2; i<MX; ++i ){
		a[i] = (a[i-1] + power(i,i))%10;
	}
	while( cin >> s, s != "0" ){
		if( s.size() > 3 ) s = s.substr( s.size()-3 );
		istringstream(s) >> x;
		cout << a[x%200] << endl;
	}
}
