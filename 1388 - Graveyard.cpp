/**
	UVa 1388 - Graveyard
	by Rico Tiongson
	Submitted: Setpember 20, 2013
	Accepted 0.012s C++
	O(n) time
*/
#include<iostream>
#include<cmath>
using namespace std;
int n, m, i;
double d, x;
int main(){
	cout.precision(4);
	cout << fixed;
	while( cin >> n >> m ){
		m += n;
		d = 0;
		for( i=1; i<n; ++i ){
			x = (double)i*m/n;
			d += abs(x-round(x))/m;
		}
		cout << d*10000 << endl;
	}
}
