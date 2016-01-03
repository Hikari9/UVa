/**
	UVa 11089 - Fi-binary Number
	by Rico Tiongson
	Submitted: September 1, 2013
	Accepted 0.012s C++
	O(logn) time
*/
#include<iostream>
#include<sstream>
#include<algorithm>
#define MX 45
using namespace std;
int fib[MX] = {1,1}, i, t, n, lim;
string fibinary( int x ){
	if( x<2 ) return x==1 ? "1" : "0";
	int digits = upper_bound( fib,fib+lim,x ) - fib - 1;
	ostringstream os;
	os << '1';
	os.width(digits-1);
	os.fill('0');
	lim = digits;
	os << right << fibinary( x-fib[digits] );
	return os.str();
}

int main(){
	for( i=2; i<MX; ++i ){
		fib[i] = fib[i-1] + fib[i-2];
	}
	cin >> t;
	while( t-- ){
		cin >> n;
		lim = MX;
		cout << fibinary(n) << endl;
	}
}
