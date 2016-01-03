/**
	UVa 10357 - Playball !!!
	by Rico Tiongson
	Submitted: June 15, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-7
using namespace std;
struct point{
	int x, y, sp;
	point(){
		scanf("%d %d %d",&x,&y,&sp);
		getchar();
	}
	// point( int X, int Y, int SP ): x(X), y(Y), sp(SP) {}
} *p;

int n, B, i, j, a, b, c, d, e, f, g, t, dx, dy;
double d1, d2;
double dist( const point& a ){
	double DX = dx-a.x, DY = dy-a.y;
	return sqrt(double(DX*DX + DY*DY));
}
int minpos(){
	// d1 = ceil(d1);
	// d2 = ceil(d2);
	if( d1<0.+eps ) return ceil(d2); // hula hula epsilon
	if( d2<0.+eps ) return ceil(d1);
	if( ceil(d1)-d1 > ceil(d2)-d2 ) return ceil(d1);
	if( ceil(d1)-d1 == ceil(d2)-d2 ) return min(ceil(d1),ceil(d2));
	return ceil(d2);
	// return d1<d2 ? ceil(d1) : ceil(d2);
}
int main(){
	// cout << fixed;
	scanf("PLAYERS=%d",&n);
	getchar();
	p = new point[n];
	scanf("BALLS=%d",&B);
	for( i=1; i<=B; ++i ){
		getchar();
		scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g);
		// solve for +t through quad form
		d2 = sqrt(b*b-4*a*c);
		d1 = (-d2-(double)b)/(2.*a);
		d2 = (d2-(double)b)/(2.*a);
		// cout << i << ':'  << ' ' << d1 << ' ' << d2 << endl;
		t = minpos();
		dx = t*d + e;
		dy = t*f + g;
		// cout << t << ' ' << dx << ' ' << dy << endl;
		if( dx<0 || dy<0 )
			printf("Ball %d was foul at (%d,%d)\n",i,dx,dy);
		else{
			// check if caught
			for( j=0; j<n; ++j ){
				if( dist(p[j])/(double)p[j].sp < (double)t+eps ){
					printf("Ball %d was caught at (%d,%d)\n",i,dx,dy);
					break;
				}
			}
			if( j==n ) printf("Ball %d was safe at (%d,%d)\n",i,dx,dy);
		}
	}
}
