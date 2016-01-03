/**
	UVa 10589 - Area
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.279s C++
	O(1) time
*/
#include<iostream>
using namespace std;
int n, a, i, m;
double x, y;
int main(){
	cout.precision(5);
	cout << fixed;
	while( cin >> n >> a, n||a ){
		m = 0;
		for( i=0; i<n; ++i ){
			cin >> x >> y;
			if( x*x + y*y < a*a && (a-x)*(a-x) + (a-y)*(a-y) < a*a && (a-x)*(a-x) + y*y < a*a && x*x + (a-y)*(a-y) < a*a ){
				++m;
			}
		}
		cout << (double)a*a*m/n << endl;
	}
}
