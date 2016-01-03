/**
	UVa 10432 - Polygon Inside A Circle
	by Rico Tiongson
	Submitted: June 6, 2013
	Accepted 0.019s C++
	O(1) time
*/
#include<iostream>
#include<cmath>
using namespace std;
long double r,n,PI(2.*acos(-1.));
int main(){
	cout.precision(3);
	cout << fixed;
	while( cin >> r >> n ) cout << n*r*r*sin(PI/n)/2. << endl;
}
