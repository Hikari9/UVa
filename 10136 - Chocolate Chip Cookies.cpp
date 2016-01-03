/**
	UVa 10136 - Chocolate Chip Cookies
	by Rico Tiongson
	Submitted: February 1, 2014
	Accepted 0.039s C++
	O(n^3) time
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-7
#define r 2.5

using namespace std;

const double PI = acos(-1.0);

struct point {
	double x, y;
	point() {}
	point( double X, double Y ): x(X), y(Y) {}
	point operator + ( const point& p ) const {
		return point( x + p.x, y + p.y );
	}
	point operator / ( double d ) const {
		return point( x / d, y / d );
	}
	
	friend ostream& operator << ( ostream& out, const point& p ){
		return out << "(" << p.x << "," << p.y << ")";
	}
};

double dist( point a, point b ){
	return hypot( a.x - b.x, a.y - b.y );
}

point median( point a, point b ){
	return (a+b) / 2.0;
}

point rotate( point p, double theta, double radius ){
	return point( p.x + radius * cos(theta), p.y + radius * sin(theta) );
}

int t, ans, n;
char buf[250];

point * intersection( point a, point b ){
	double d = dist(a, b);
	if( d > 2*r ) return NULL;
	double theta = acos( d / (2.0*r) ) * 2.0;
	double x = r * sin( theta / 2.0 );
	double angle = atan2( b.y - a.y, b.x - a.x );
	point * p = new point[2];
	point m = median( a, b );
	p[0] = rotate( m, angle + PI/2.0, x );
	p[1] = rotate( m, angle - PI/2.0, x );
	return p;
}

point p[201];

int main(){
	scanf( "%d", &t );
	gets(buf); gets(buf);
	while( t-- ){
		ans = 0;
		n = 0;
		while( gets(buf) && buf[0] ){
			sscanf( buf, "%lf %lf", &p[n].x, &p[n].y );
			++n;
		}
		if( n ) ans = 1;
		for( int i=0; i<n; ++i ){
			for( int j=i+1; j<n; ++j ){
				point * c = intersection( p[i], p[j] );
				if( c == NULL ) continue;
				for( int k=0; k<2; ++k ){
					// cout << p[i] << " " << p[j] << " " << c[k] << " " << dist(p[i], c[k]) << " " << dist(p[j], c[k]) << endl;
					int cnt = 0;
					for( int l=0; l<n; ++l ){
						if( dist( c[k], p[l] ) < r + eps ){
							// cout << ":: " << p[l] << endl;
							++cnt;
						}
					}
					// cout << endl;
					ans = max( ans, cnt );
				}
			}
		}
		printf( "%d\n", ans );
		if( t ) putchar( '\n' );
	}
}
