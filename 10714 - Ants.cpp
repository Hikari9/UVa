/**
	UVa 10714 - Ants
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.209s C++
	O(n) time
*/
#include <iostream>
using namespace std;

int t, l, n, a;

int main(){
	cin >> t;
	while( t-- ){
		cin >> l >> n;
		int mx1 = 0, mx2 = 0;
		for( int i=0; i<n; ++i ){
			cin >> a;
			int b = l - a;
			if( b < a ) swap( a, b );
			mx1 = max( mx1, a );
			mx2 = max( mx2, b );
		}
		cout << mx1 << " " << mx2 << endl;
	}
}
