/**
	UVa 11610 - Reverse Prime
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 0.362s C++
	O(nloglogn) sieve + O(1) query + O(n+logn) delete
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;

bool *isPrime;
vector<int> pr, v, pf;

void sieve( int );
int reverse( int );
int sumPrimeFactors( int );
void print( int i, int I ){
	while( i<I ){
		cout << v[i] << " : " << pf[i] << endl;
		++i;
	}
}

int main(){
	sieve( 1000000 );
	int i, I, x;
	I = pr.size();
	v.resize(I);
	pf.resize(I);
	for( i=0; i<I; ++i ){
		v[i] = reverse(pr[i]);
	}
	sort( v.begin(), v.end() );
	I = v.size();
	pf[0] = sumPrimeFactors( v[0] );
	for( i=1; i<I; ++i ){
		pf[i] = sumPrimeFactors( v[i] ) + pf[i-1];
	}
	char query[2];
	while( scanf( "%s %d", query, &i )==2 ){
		if( *query=='q' ){
			printf( "%d\n", pf[i] );
		}
		else if( *query=='d' ){
			// delete
			I = lower_bound( v.begin(), v.end(), i ) - v.begin();
			if( v[I]!=i ) continue;
			x = pf[I];
			if( I!=0 ) x -= pf[I-1];
			// cout << "OLD:" << endl;
			// print( 0, 5 );
			// cout << endl;
			v.erase( v.begin() + I );
			pf.erase( pf.begin() + I );
			// cout << "MID:" << endl;
			// print( 0, 5 );
			// cout << endl;
			while( I<pf.size() )
				pf[I++] -= x;
			// cout << "NEW:" << endl;
			// print( 0, 5 );
			// cout << endl;
		}
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

int reverse( int x ){
	int y = 0;
	for( int i=0; i<7; ++i ){
		y = y*10 + x%10;
		x/=10;
	}
	return y;
}

int sumPrimeFactors( int x ){
	int sum = 0;
	for( int j=0; j<pr.size() && pr[j]*pr[j] <= x; ++j ){
		while( x%pr[j]==0 ){
			// sum += pr[j];
			++sum;
			x /= pr[j];
		}
	}
	if( x!=1 ) ++sum;
	return sum;
}
