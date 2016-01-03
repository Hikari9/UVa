/**
	UVa 12043 - Divisors
	by Rico Tiongson
	Submitted: September 1, 2013
	Accepted 0.105s C++
	O(nsqrtn) pregen + O(n) time
*/
#include<iostream>
#include<cstring>
#define mx 100001
using namespace std;

int i, j, x, d[mx], o[mx], t, a, b, k, m;
long long D, O;

int main(){
	d[1] = 1;
	o[1] = 1;
	for( i=2; i<mx; ++i ){
		d[i] = 2;
		o[i] = 1+i;
		// x = i;
		for( j=2; j*j < i; ++j ){
			if( i%j==0 ){
				d[i] += 2;
				o[i] += j + (i/j);
			}
		}
		if( j*j==i )
			++d[i], o[i]+=j;
	}
	cin >> t;
	while( t-- ){
		cin >> a >> b >> k;
		D = O = 0;
		m = a%k;
		if( m ) a += k-m;
		m = b%k;
		b -= m;
		while( a<=b ){
			D += d[a];
			O += o[a];
			a += k;
		}
		cout << D << " " << O << endl;
	}
}
