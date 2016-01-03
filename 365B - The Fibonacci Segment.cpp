/**
	CodeForces 365B - The Fibonacci Segment
	by Rico Tiongson
	Submitted: November 22, 2013
	Accepted 0.078s C++
	O(n) time
*/
#include <iostream>
using namespace std;
typedef long long lag;
lag a[100005];
bool b[100005];
int n;
int main(){
	cin >> n;
	for( int i=1; i<=n; ++i ){
		cin >> a[i];
		b[i] = ( i > 2 && a[i] == a[i-2] + a[i-1] );
	}
	int mx = 0;
	for( int l=1, r; l<=n; ++l ){
		if( b[l] ){
			for( r=l+1; r<=n; ++r ){
				if( !b[r] ) break;
			}
			mx = max( mx, r - l );
			l = r;
		}
	}
	cout << min( n, (mx+2) ) << endl;
}
