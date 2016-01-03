/**
	UVa 11415 - Count the Factorials
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 0.912s C++
	O(n^2logn) pregen + O(logn) time
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define sz 2703663
#define pz 1644
#define mz 259
using namespace std;
bool isPrime[pz];
int c[sz], pr[mz];
int i, j, lim, sum, t, n, id;
int getPrimeFactorSum( int x ){
	sum = 0;
	for( j=0; j<mz && pr[j]*pr[j]<=x; ++ j){
		while( x%pr[j]==0 ){
			++sum;
			x/=pr[j];
		}
	}
	if( x!=1 ) ++sum;
	return sum;
}
int func( int x ){
	return upper_bound( c, c+sz, n ) - c;
}
int main(){
	pr[id++] = 2;
	memset( isPrime, 1, sizeof isPrime );
	for( i=3; i<pz; i+=2 ){
		if( isPrime[i] ){
			pr[id++] = i;
			for( j=i*i; j<pz; j+=i ){
				isPrime[j] = false;
			}
		}
	}
	for( i=1; i<sz; ++i ){
		getPrimeFactorSum(i);
		c[i] = sum+c[i-1];
	}
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d", &n );
		printf( "%d\n", func(n) );
	}
}
