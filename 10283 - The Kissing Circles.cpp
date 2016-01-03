/**
	UVa 10283 - The Kissing Circles
	by Rico Tiongon
	Submitted: Feb 2, 2014
	Accepted 0.089s C++
	O(1) time
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);
int R, n;

int main(){
	while( scanf( "%d%d", &R, &n ) != EOF ){
		double theta = PI*(n-2)/n;
		double r = (R * ( 1 + cos(0.5*theta) ) - R) / ( 1 + cos(0.5*theta));
		double sector = 0.5*n*r*r*theta;
		double polygon = n*r*sqrt( (R-r)*(R-r) - r*r );
		double blue = polygon - sector;
		double grey = PI*n*r*r;
		double green = PI*R*R - grey - blue;
		if( n == 1 ){
			r = R;
			blue = 0;
			green = 0;
		}
		printf( "%.10lf %.10lf %.10lf\n", r, blue, green );
	}
}
