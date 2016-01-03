/**
	UVa 11287 - Pseudoprime Numbers
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.025s C++
	O(nloglogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define mx 31623
using namespace std;
bool pr[mx];
int i, j, p;
long long a;
long long bigmod( int expo ){
	if( !expo ) return 1ll;
	long long half = bigmod( expo/2 )%p;
	if( expo%2 ) return (((half*half)%p)*a)%p;
	return (half*half)%p;
}
bool isprime( int _ ){
	if( _<mx ) return pr[_];
	if( _%2==0 ) return false;
	j = sqrt( _ )+1;
	for( i=3; i<j; i+=2 ){
		if( pr[i] ){
			if( _%i==0 ) return false;
		}
	}
	return true;
}
int main(){
	memset( pr, 1, sizeof( pr ) );
	pr[1] = false;
	for( j=4; j<mx; j+=2 ) pr[j] = false;
	for( i=3; i<mx; i+=2 ){
		if( pr[i] ){
			for( j=2*i; j<mx; j+=i ){
				pr[j] = false;
			}
		}
	}
	start:
	scanf("%d %lld", &p, &a);
	if( !a && !p ) return 0;
	if( isprime(p) ) puts("no");
	else{
		if(bigmod(p)==a) puts("yes");
		else puts("no");
	}
	getchar();
	goto start;
}
