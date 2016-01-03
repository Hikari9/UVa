/**
	UVa 10678 - The Grazing Cow
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.019s C++
	O(1) time
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos( -1.0 );

int t, d, l;
double c;

int main(){
	cout.precision(3);
	cout << fixed;
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d %d", &d, &l );
		double c = d/2.0;
		double a = (l - d)/2.0 + c;
		double b = sqrt(a*a - c*c);
		printf( "%.3lf\n", PI * a * b );
	}
}
