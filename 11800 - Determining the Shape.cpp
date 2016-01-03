/**
	UVa 11800 - Determining the Shape
	by Rico Tiongson
	Submitted: Feb 3, 2014
	Accepted 0.332s C++
	O(nlogn + n) time
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#define eps 1e-7
using namespace std;
typedef long long lag;

// const double PI = acos(-1.0);

struct point {
	lag x, y;
	point() {}
	point( lag X, lag Y ): x(X), y(Y) {}
	bool operator < ( const point& p ) const {
		return ( y == p.y ? x < p.x : y < p.y );
	}
	point operator - ( const point& p ) const {
		return point( x - p.x, y - p.y );
	}
};

lag dot( point a, point b ){
	return a.x * b.x + a.y * b.y;
}

lag dist( point a, point b ){
	return dot(a-b, a-b);
}

point quad[4];

lag cross( point a, point b ){
	return a.x * b.y - a.y * b.x;
}

lag cross( point a, point b, point c ){
	return cross(a,b) + cross(b,c) + cross(c,a);
}

bool sorter( const point& a, const point& b ){
	lag c1 = cross( a, quad[0], b );
	lag c2 = cross( b, quad[0], a );
	return c2 > c1;
}

void Sort(){
	swap( *min_element( quad, quad+4 ), quad[0] );
	sort( quad+1, quad+4, sorter );
}

lag t, tc;

bool square();
bool rectangle();
bool rhombus();
bool parallelogram();
bool trapezium();

bool rhombus(){
	lag d = dist( quad[0], quad[3] );
	for( lag i=1; i<4; ++i ){
		if( dist( quad[i], quad[i-1] ) != d ) return false;
	}
	return true;
}

bool parallelogram(){
	lag d[4];
	for( lag i=0, j=3; i<4; j=i++ ){
		d[i] = dist( quad[i], quad[j] );
	}
	return ( d[0] == d[2] ) && ( d[1] == d[3] ) ;
}

bool rectangle(){
	for( lag i=0; i<4; ++i ){
		lag prev = (i+3) % 4;
		lag next = (i+1) % 4;
		point a = quad[prev];
		point b = quad[i];
		point c = quad[next];
		if( dot( a-b, c-b ) > 0 ) return false;
	}
	return true;
}

bool square(){
	return rhombus() && rectangle();
}

bool trapezium(){
	// lag d[4];
	point c[4];
	for( lag i=0, j=3; i<4; j=i++ ){
		c[i] = quad[i] - quad[j];
		// d[i] = dist( quad[i], quad[j] );
	}
	for( lag i=0; i<2; ++i ){
		if( cross( c[i], c[i+2] ) == 0 ) return true;
	}
	return false;
}

bool convex(){
	for( lag i=0; i<4; ++i ){
		lag j = (i+3) % 4;
		lag k = (i+1) % 4;
		if( cross( quad[j], quad[i], quad[k] ) <= 0 ) return false;
	}
	return true;
}

int main(){
	cin >> t;
	while( t-- ){
		for( lag i=0; i<4; ++i ){
			cin >> quad[i].x >> quad[i].y;
		}
		Sort();
		cout << "Case " << ++tc << ": ";
		if( !convex() ) cout << "Ordinary Quadrilateral" << endl;
		else if( square() ) cout << "Square" << endl;
		else if( rectangle() ) cout << "Rectangle" << endl;
		else if( rhombus() ) cout << "Rhombus" << endl;
		else if( parallelogram() ) cout << "Parallelogram" << endl;
		else if( trapezium() ) cout << "Trapezium" << endl;
		else cout << "Ordinary Quadrilateral" << endl;
	}
}
