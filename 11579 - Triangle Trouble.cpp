/**
	UVa 11579 - Triangle Trouble
	by Rico Tiongson
	Submitted: August 26, 2013
	Accepted 0.512s C++
	O(nlogn) time
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#define eps 1e-9
using namespace std;
int t, n, i, j;
double l[10005], area, p;
int main(){
	cout.precision(2);
	cout << fixed;
	cin >> t;
	while( t-- ){
		cin >> n;
		if( n<3 ){
			cout << "0.00" << endl;
			continue;
		}
		for( i=0; i<n; ++i ){
			cin >> l[i];
		}
		// sort( l, l+n );
		make_heap( l, l+n );
		pop_heap( l, l+(n--) );
		pop_heap( l, l+(n--) );
		area = 0;
		while( n>0 ){
			if( l[n+1] + eps < l[n] + l[0] ){
				p = ( l[n] + l[n+1] + l[0] )*0.5;
				area = max(area,sqrt(p)*sqrt(p-l[n])*sqrt(p-l[n+1])*sqrt(p-l[0]));
				// area = sqrt(p*(p-l[n])*(p-l[n+1])*(p-l[0]));
				// break;
			}
			// pop
			pop_heap( l, l+(n--) );
		}
		cout << area << endl;
	}
}
