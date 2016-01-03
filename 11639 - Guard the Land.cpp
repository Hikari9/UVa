/**
	UVa 11639 - Guard the Land
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.025s C++
	O(1) time
*/
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a, b, c, d, e, f, g, h;
int main(){
	scanf( "%d", &n );
	for( int tc=1; tc<=n; ++tc ){
		scanf( "%d%d%d%d", &a, &b, &c, &d );
		scanf( "%d%d%d%d", &e, &f, &g, &h );
		int x, y, z, t;
		x = max(a, e);
		y = max(b, f);
		z = min(c, g);
		t = min(d, h);
		int strong = (z-x) * (t-y);
		if( x > z || y > t ) strong = 0;
		int weak = (c-a) * (d-b) + (g-e) * (h-f) - 2*strong;
		int out = 100 * 100 - weak - strong;
		printf( "Night %d: %d %d %d\n", tc, strong, weak, out );
	}
}
