/**
	UVa 10451 - Ancient Village Sports
	by Rico Tiongson
	Submitted: September 16, 2013
	Accepted 0.042s C++
	O(2) time
*/
#include<cstdio>
#include<cmath>
using namespace std;
const double PI( 2*acos(0) );
int n, tc;
double A, a2, r2;
int main(){
	while( scanf( "%d %lf", &n, &A )==2 ){
		if(n<3) return 0;
		r2 = A/(n*cos(PI/n)*sin(PI/n));
		a2 = r2 * cos(PI/n) * cos(PI/n);
		printf( "Case %d: %.5f %.5f\n", ++tc, PI*r2 - A, A - PI*a2 );
	}
}
