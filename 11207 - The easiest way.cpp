/**
	UVa 11207 - The easiest way
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.032s C++
	O(n) time
*/
#include <iostream>
using namespace std;

int main(){
	int n;
	while( cin >> n, n ){
		int w, h;
		double mx = 0.0;
		int mxi = 0;
		for( int i=0; i<n; ++i ){
			cin >> w >> h;
			double test = max( min(w, h)/2.0, max( min<double>(w/4.0, h), min<double>(w, h/4.0) ) );
			if( test > mx ){
				mx = test;
				mxi = i;
			}
		}
		cout << mxi+1 << endl;
	}
}
