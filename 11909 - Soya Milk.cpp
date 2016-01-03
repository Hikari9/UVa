/**
	UVa 11909 - Soya Milk
	by Rico Tiongson
	Submitted: September 26, 2013
	Accepted 0.022s C++
	O(1) time
*/
#include<cstdio>
#include<cmath>
const double PI = acos(-1.0);
double RAD( double deg ){ return deg*PI/180.0; }
double a;
int l, w, h, theta;
int main(){
	while( scanf("%d %d %d %d", &l, &w, &h, &theta)==4 ){
		a = l*l*tan(RAD(theta));
		if( a > l*h ){
			printf( "%.3lf mL\n", w*0.5*h*h/tan(RAD(theta)) );
		}
		else printf( "%.3lf mL\n", (l*h-0.5*a)*w );
	}
}
