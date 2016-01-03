/**
	CodeForces 276D - Little Girl and Maximum XOR
	by Rico Tiongson
	Submitted: December 6, 2013
	Accepted 30ms GNU C++
	O(logn) time
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long lag;

lag a, b;
int i;
string x, y;

int main(){
	scanf( "%I64d %I64d", &a, &b );
	for( i=0; i<64; ++i ){
		x.push_back( '0' + (a&1) );
		y.push_back( '0' + (b&1) );
		a >>= 1;
		b >>= 1;
	}
	lag ans = 0;
	// cout << x << endl << y << endl;
	for( i=63; i>=0; --i ){
		if( x[i] != y[i] ){
			ans = (1LL<<(i+1)) - 1;
			break;
		}
	}
	printf( "%I64d\n", ans );
}
