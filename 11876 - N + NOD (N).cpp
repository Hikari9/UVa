/**
	UVa 11876 - N + NOD (N)
	by Rico Tiongson
	Submitted: August 25, 2013
	Accepted 0.259s C++
	O(nsqrtn + n) pregen + O(1) time
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> NOD;
int divisors( int );
int i, t, A, B, tc, acu[1000002];

int main(){
	NOD.push_back(1);
	while( NOD.back()<=1000000 ){
		NOD.push_back( NOD.back() + divisors(NOD.back()) );
	}
	NOD.pop_back();
	for( i=0; i<NOD.size(); ++i ){
		acu[NOD[i]] = 1;
	}
	for( i=1; i<1000002; ++i ){
		acu[i] += acu[i-1];
	}
	scanf( "%d", &t );
	while( tc<t ){
		scanf( "%d %d", &A, &B );
		printf( "Case %d: %d\n", ++tc, acu[B]-acu[A-1] );
	}
}
int divisors( int x ){
	int ans = 1 + (x!=1), j;
	for( j=2; j*j<x; ++j ){
		if( x%j==0 ){
			ans += 2;
		}
	}
	if( j*j==x ) ++ans;
	return ans;
}
