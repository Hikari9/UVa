/**
	UVa 833 - Water Falls
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.016s C++
	O(n^2) time
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#define eps 0.0001
using namespace std;
struct point{
	int x, y;
	point() {}
	point( int X, int Y ): x(X), y(Y) {}
	bool operator<( const point& _ )const{
		return y < _.y;
	}
};
istream& operator>>( istream& in, point& _ ){
	return in >> _.x >> _.y;
}
struct line{
	int next;
	point a, b;
	double m, y_intercept;
	void normalize(){
		if( b<a ) swap( a, b );
		m = double(b.y-a.y)/(b.x-a.x);
		y_intercept = a.y-m*a.x;
		// cout << m << ' ' << y_intercept << endl;
	}
	line() {}
	line( const point& A, const point& B ): a(A), b(B) { normalize(); }
	line( int x, int y, int x_, int y_ ): a(x,y), b(x_,y_) { normalize(); }
	double operator()( int x )const{ return m*x+y_intercept; }
};
istream& operator>>( istream& in, line& _ ){
	in >> _.a >> _.b;
	_.normalize();
	return in;
}
int t, np, ns, i, j;
double mn, ytemp;
point src;
double drop( const point& p, const line& ln ){
	// check range
	if( p.x>=min(ln.a.x,ln.b.x) && p.x<=max(ln.a.x,ln.b.x) ){
		return (double)p.y-ln( p.x );
	}
	return -1.0;
}
int main(){
	cin >> t;
	while( t ){
		cin >> np;
		line l[np];
		for( i=0; i<np; ++i ){
			cin >> l[i];
			// check for vertical, remove
			if( l[i].b.x == l[i].a.x ) --np, --i;
		}
		// get "next" dropping point for all lines
		for( i=0; i<np; ++i ){
			// get nearest dropping point
			l[i].next = -1; // default minimum: horizontal line
			mn = l[i].a.y;
			for( j=0; j<np; ++j ){
				if( j==i ) continue;
				ytemp = drop( l[i].a, l[j] );
				if( ytemp>=-eps ){
					if( ytemp < mn ){
						mn = ytemp;
						l[i].next = j;
					}
				}
			}
		}
		cin >> ns;
		while( ns-- ){
			cin >> src;
			// retrieve points underneath then sort
			i = -1;
			mn = src.y;
			for( j=0; j<np; ++j ){
				ytemp = drop( src, l[j] );
				if( ytemp>=-eps ){
					if( ytemp < mn ){
						mn = ytemp;
						i = j;
					}
				}
			}
			// trace back
			if( i==-1 ){
				// drops to horizontal line immediately
				cout << src.x << endl;
			}
			else{
				while( l[i].next != -1 ){
					i = l[i].next;
				}
				cout << l[i].a.x << endl;
			}
		}
		if( --t ) cout << endl;
	}
}
