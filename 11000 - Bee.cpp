/**
	UVa 11000 - Bee
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.015s C++
	O(n) pregen
*/
#include<iostream>
#define sz 45
using namespace std;
int n;
unsigned m[sz], f[sz];
int main(){
	m[0] = 0;
	f[0] = 1;
	for( int i=1; i<sz; ++i ){
		m[i] = f[i-1] + m[i-1];
		f[i] = m[i-1]+1;
	}
	while( cin >> n, ~n ){
		cout << m[n] << " " << f[n]+m[n] << endl;
	}
}
