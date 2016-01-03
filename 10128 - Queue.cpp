/**
	UVa 10128 - Queue
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.019s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define MX 14
using namespace std;
typedef long long lag;
lag dp[MX][MX];
lag fact[MX] = {1,1};
lag choose( int n, int k ){
	return fact[n]/(fact[k]*fact[n-k]);
}
lag stirling( int n, int k ){
	if( n==0 && k==0 ) return 1;
	if( n==0 || k==0 ) return 0;
	if( dp[n][k]!=0 ) return dp[n][k];
	dp[n][k] = stirling(n-1,k-1) - (n-1)*stirling(n-1,k);
	return dp[n][k];
}
lag a_stirling( int n, int k ){
	lag ans = stirling(n,k);
	return ans>=0 ? ans : -ans;
}

lag calc( int n, int p, int q ){
	if( p<1 || q<1 || p+q>n+1 || p+q<=2 ){
		return 0;
	}
	int N = p+q-2;
	int K = q-1;
	return a_stirling(n-1,N)*choose(N,K);
}

int t, n, p, q, i;
int main(){
	for( i=2; i<MX; ++i ) fact[i] = fact[i-1]*i;
	scanf( "%d", &t );
	while(t--){
		scanf( "%d %d %d", &n, &p, &q );
		printf( "%lld\n", calc(n,p,q) );
	}
}
