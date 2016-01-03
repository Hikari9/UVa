/**
	UVa 10005 - Packing polygons
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.018s C++
	O(n^3) time
*/
#include <iostream>
#include <cmath>

#define eps 1e-7

using namespace std;

struct point {
	double x, y;
	point() {}
	point( double X, double Y ): x(X), y(Y) {}
};

double R;

double dist( point a, point b ){
	return hypot( a.x - b.x, a.y - b.y );
}

point rotate( point p, double angle, double radius ){
	return point( p.x + radius * cos(angle), p.y + radius * sin(angle) );
}

point * getCircle( point a, point b ){
	double d = dist(a, b);
	if( d > 2*R + eps ) return NULL;
	double alpha = atan2( b.y - a.y, b.x - a.x );
	double theta = acos( 0.5 * d / R );
	point * ans = new point[2];
	ans[0] = rotate( a, alpha + theta, R );
	ans[1] = rotate( a, alpha - theta, R );
	return ans;
}

int n;
point p[101];

int main(){
	while( cin >> n, n ){
		for( int i=0; i<n; ++i ){
			cin >> p[i].x >> p[i].y;
		}
		cin >> R;
		bool ok = false;
		for( int i=0; i<n; ++i ){
			for( int j=i+1; j<n; ++j ){
				point * c = getCircle( p[i], p[j] );
				if( c == NULL ) continue;
				for( int k=0; k<2; ++k ){
					ok = true;
					for( int l=0; l<n; ++l ){
						if( dist( c[k], p[l] ) > R + eps ){
							ok = false;
							break;
						}
					}
					if( ok ) goto done;
				}
			}
		}
		done:
		if( ok ){
			cout << "The polygon can be packed in the circle." << endl;
		}
		else{
			cout << "There is no way of packing that polygon." << endl;
		}
	}
}
