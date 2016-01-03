/**
	UVa 11473 - Campus Roads
	by Rico Tiongson
	Submitted: August 25, 2013
	Accepted 0.026s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct point{
	double x, y;
	point() {}
	point( double X, double Y ): x(X), y(Y) {}
};
inline double dist( const point& a, const point& b ){
	return hypot( a.x-b.x, a.y-b.y );
}
point p[105];
double d[105], ave, acu, angle, x, y;;
int n, k, t, tc, i;
int main(){
	scanf( "%d", &n );
	while( tc<n ){
		scanf( "%d %d", &k, &t );
		for( i=0; i<k; ++i ){
			scanf( "%lf %lf", &p[i].x, &p[i].y );
		}
		ave = 0;
		for( i=1; i<k; ++i ){
			d[i] = dist( p[i-1], p[i] );
			ave += d[i];
		}
		ave /= (t-1);
		// cout << "AVE: " << ave << endl;
		acu = 0;
		printf( "Road #%d:\n", ++tc );
		// auto print first point
		printf( "%.2lf %.2lf\n", p[0].x, p[0].y );
		for( i=1; i<k; ++i ){
			acu += d[i];
			while( acu > ave-1e-7 ){
				acu -= ave;
				// cout << "Y: " << p[i].y-p[i-1].y << endl;
				// cout << "X: " << p[i].x-p[i-1].x << endl;
				angle = atan2( (p[i].y-p[i-1].y), (p[i].x-p[i-1].x) );
				// cout << "ANGLE: " << angle << endl;
				// cout << "COS:   " << cos(angle) << endl;
				// cout << "SIN:   " << sin(angle) << endl;
				x = p[i].x - acu*cos(angle);
				y = p[i].y - acu*sin(angle);
				printf( "%.2lf %.2lf\n", x, y );
			}
		}
		putchar('\n');
	}
}
