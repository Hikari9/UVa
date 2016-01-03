/**
	UVa 11264 - Coin Collector
	by Rico Tiongson
	Submitted: August 16, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t, n, c[1005], a[1005], mx, i, j;
long long x;
int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		for( i=0; i<n; ++i )
			cin >> c[i];
		x = 0;
		mx = j = 0;
		for( i=0; i<n; ++i ){
			// bisect
			while( x>=c[i] )
				x -= a[--j];
			x += (a[j] = c[i]);
			mx = max(mx,++j);
		}
		cout << mx << endl;
	}
}
