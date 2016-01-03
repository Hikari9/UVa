/**
	UVa 10856 - Recover Factorial
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 0.955s C++
	O(nloglogn) sieve + O(n logsqrtn) generatePrimeFactorSum + O(logn) time
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_FACT 2703664
using namespace std;

bool *isPrime;
vector<int> pr;
void sieve( int );

int *pf, tc;

void generatePrimeFactorSum( int );
int primeFactorSum( int );

int main(){
	sieve( MAX_FACT );
	generatePrimeFactorSum( MAX_FACT );
	int i, x;
	for( i=1; i<MAX_FACT; ++i ){
		pf[i] += pf[i-1];
	}
	
	while( scanf( "%d", &i )==1 ){
		if( i<0 ) break;
		printf( "Case %d: ", ++tc );
		x = lower_bound( pf, pf+MAX_FACT, i )-pf;
		if( pf[x]==i ) printf( "%d!\n", x );
		else puts("Not possible.");
	}
}


void sieve( int maxNum ){
	isPrime = new bool[maxNum];
	memset( isPrime, -1, maxNum );
	isPrime[0] = isPrime[1] = false;
	long long i, j;
	pr.clear();
	pr.push_back(2);
	for( j=4; j<maxNum; j+=2 ) isPrime[j] = false;
	for( i=3; i<maxNum; i+=2 ){
		if( isPrime[i] ){
			pr.push_back(i);
			for( j=i*i; j<maxNum; j+=i ) isPrime[j] = false;
		}
	}
}

void generatePrimeFactorSum( int maxNum ){
	pf = new int[maxNum];
	pf[0] = pf[1] = 0;
	for( int i=2; i<maxNum; ++i ){
		pf[i] = primeFactorSum(i);
	}
}

int primeFactorSum( int x ){
	int sum = 0;
	for( int i=0; i<pr.size() && pr[i]*pr[i]<=x; ++i ){
		while( x%pr[i]==0 ){
			++sum;
			x/=pr[i];
		}
	}
	if( x!=1 ) ++sum;
	return sum;
}
