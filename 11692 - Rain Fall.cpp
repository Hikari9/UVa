/**
	UVa 11692 - Rain Fall
	by Rico Tiongson
	Submitted: August 29, 2013
	Accepted 0.019s C++
	O(1) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int N;
double L, K, T1, T2, H;
double disc, a, b, c;
double mny, mxy, x;
int main(){
	scanf( "%d", &N );
	while( N-- ){
		scanf( "%lf %lf %lf %lf %lf", &L, &K, &T1, &T2, &H );
		if( H<L ){
			printf( "%.6lf %.6lf\n", H, H );
			continue;
		}
		// get one root
		// T1 x^2 -(K*(T1+T2)+H) x + (K*L) = 0
		mny = mxy = H;
		a = T1;
		b = -(K*(T1+T2)+H);
		c = K*L;
		disc = b*b - 4.0*a*c;
		if( disc >= 0.0 ){
			disc = sqrt(disc);
			x = 0.5*(-b+disc)/a;
			// dy^2/dx^2
			mxy = T1*x;
		}
		if( H>L ) mny = mxy;
		printf( "%.6lf %.6lf\n", mny, mxy );
	}
}

