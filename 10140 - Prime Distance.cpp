/**
	UVa 612 - Prime Distance
	by Rico Tiongson
	Submitted: October 12, 2013
	Accepted 0.239s C++
	O(nloglogn) pregen + O(nloglogn) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define MX 46341
using namespace std;

vector<unsigned> pr;
bool is[MX];
bool check[1000005];

unsigned i, j, a, b, prev, mx, mn, x[2], y[2], diff;

int main(){
	memset( is, 1, sizeof is );
	is[0] = is[1] = 0;
	pr.push_back(2);
	for( i=4; i<MX; i+=2 ){
		is[i] = 0;
	}
	for( i=3; i<MX; i+=2 ){
		if( is[i] ){
			pr.push_back(i);
			for( j=i*i; j<MX; j+=i ){
				is[j] = 0;
			}
		}
	}
	while( cin >> a >> b ){
		memset( check, 1, sizeof check );
		if( a < 2 ) a = 2;
		for( i=0; i<pr.size(); ++i ){
			if( pr[i]*pr[i] > b ) break;
			for( j=max(pr[i]*pr[i],a); j <= b && j%pr[i]!=0 ; ++j );
			for( ; j<=b; j+=pr[i] ) check[j-a] = 0;
		}
		prev = 0;
		mx = 0;
		mn = -1;
		j = b - a;
		for( i=0; i<=j; ++i ){
			if( check[i] ) break;
		}
		prev = i;
		for( ++i; i<=j; ++i ){
			if( check[i] ){
				diff = i - prev;
				if( diff < mn ){
					mn = diff;
					x[0] = prev;
					x[1] = i;
				}
				if( diff > mx ){
					mx = diff;
					y[0] = prev;
					y[1] = i;
				}
				prev = i;
			}
		}
		if( mn==-1 ){
			cout << "There are no adjacent primes." << endl;
		}
		else{
			// cout << "(" << mn << ") ";
			cout << x[0]+a << "," << x[1]+a << " are closest, " << y[0]+a << "," << y[1]+a << " are most distant." << endl;
		}
	}
}
