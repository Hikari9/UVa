/**
	UVa 11466 - Largest Prime Divisor
	by Rico Tiongson
	Submitted: August 29, 2013
	Accepted 0.512s C++
	O(nloglogn) sieve + O(sqrtn) time
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#define mx 10000000
using namespace std;

bool *isPr;
vector<int> pr;
void sieve(int);
long long factorize(long long);

long long n, ans;
int i, j, c;

int main(){
	sieve(mx);
	while( scanf( "%lld", &n )==1 ){
		if( !n ) return 0;
		if( n<0 ) n = -n;
		printf( "%lld\n", factorize(n) );
	}
}

long long factorize( long long x ){
	ans = -1;
	c = 0;
	for( i=0; (long long)pr[i]*pr[i]<=x; ++i ){
		if( x%pr[i]==0 ){
			ans = pr[i];
			++c;
			do{
				x/=pr[i];
			} while( x%pr[i]==0 );
		}
	}
	if( x>1 ){
		ans = x;
		++c;
	}
	return c>1 ? ans : -1LL;
}

void sieve( int mxNum ){
	isPr = new bool[mxNum];
	memset( isPr, -1, mxNum );
	pr.clear();
	pr.push_back(2);
	for( j=4; j<mxNum; j+=2 ){
		isPr[j] = false;
	}
	for( i=3; i<mxNum; i+=2 ){
		if( isPr[i] ){
			pr.push_back(i);
			if( (long long)i*i>=mxNum ) continue;
			for( j=i*i; j<mxNum; j+=i ){
				isPr[j] = false;
			}
		}
	}
}