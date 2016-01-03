/**
	UVa 1230 - MODEX
	by Rico Tiongson
	Submitted: June 29, 2013
	Accepted 0.012s C++
	O(logn) time
*/
#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned long long lag;
lag x, xn, y;
int t, n;
lag powmod( lag e ){
	if( !e ) return 1;
	lag half = powmod( e/2 );
	if( e%2 )
	return (xn*(half*half)%n)%n;
	return (half*half)%n;
}
int main(){
	scanf("%d", &t);
	while( t ){
		scanf("%llu %llu %d",&x,&y,&n);
		xn = x%n;
		printf("%llu\n",powmod(y));
		--t;
	}
}
