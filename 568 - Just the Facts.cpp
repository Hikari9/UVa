/**
	UVa 568 - Just the Facts
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.015s C++
	O(n) pregen + O(1) time
*/
#include<iostream>
using namespace std;
int main(){
	int f = 1;
	int dig[10001] = {1, 1};
	for( int i=2; i<10001; ++i ){
		f *= i;
		while( f%10==0 ) f/=10;
		f %= 100000;
		dig[i] = f%10;
	}
	int n;
	while( cin >> n ){
		cout.width( 5 );
		cout.fill( ' ' );
		cout << n << " -> " << dig[n] << endl;
	}
}
