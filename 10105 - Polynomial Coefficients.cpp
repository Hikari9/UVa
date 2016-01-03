/**
	UVa 10105 - Polynomial Coefficients
	by Rico Tiongson
	Submitted: September 15, 2013
	Accepted 0.016s C++
	O(n) time
*/
#include<cstdio>
int n, k, i, x;
long long f[14] = {1,1}, y;
int main(){
	for( n=2; n!=14; ++n ) f[n] = f[n-1]*n;
	while( scanf( "%d %d", &n, &k )==2 ){
		y = f[n];
		for( i=0; i<k; ++i ){
			scanf( "%d", &x );
			y /= f[x];
		}
		printf( "%lld\n", y );
	}
}
