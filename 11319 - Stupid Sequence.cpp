/**
	UVa 11319 - Stupid Sequence
	by Rico Tiongson
	Submitted: January 21, 2014
	Accepted 0.169s C++
	O(n^3) time
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
// #include <ctime>
#define MX 1501
#define eps 1e-7
#define D 6
using namespace std;
typedef unsigned long long ull;

vector<double> a(D+1), b(D+1);
vector<vector<double> > m(D+1, vector<double>(D+1));

vector<ull> ua(D+1);

ull f( ull x ){
	ull sum = 0;
	ull base = 1;
	for( int i=0; i<a.size(); ++i ){
		sum += ua[i] * base;
		base *= x;
	}
	return sum;
}

bool gauss(){
	// cout << "HERE" << endl;
	int n = b.size();
	for( int p=0; p<n; ++p ){
		int mx = p;
		for( int i=p+1; i<n; ++i ){
			if( abs(m[i][p]) > abs(m[mx][p]) ) mx = i;
		}
		// cout << mx << endl;
		swap( m[p], m[mx] );
		swap( b[p], b[mx] );
		if( abs(m[p][p]) < eps ) return false;
		for( int i=p+1; i<n; ++i ){
			double alpha = m[i][p] / m[p][p];
			b[i] -= alpha * b[p];
			for( int j=p; j<n; ++j ){
				m[i][j] -= alpha * m[p][j];
			}
		}
	}
	for( int i=n-1; i>=0; --i ){
		double sum = 0;
		for( int j=i+1; j<n; ++j ){
			sum += a[j] * m[i][j];
		}
		a[i] = (b[i] - sum) / m[i][i];
	}
	return true;
}


int n;
unsigned long long d[MX];

int main(){
	cin >> n;
	while( n-- ){
		for( int i=1; i<MX; ++i ){
			cin >> d[i];
		}
		// cout << "HERE" << endl;
		for( int i=1; i<=D+1; ++i ){
			for( int j=0; j<=D; ++j ){
				m[i-1][j] = pow(i, j);
			}
			b[i-1] = d[i];
		}
		bool ok = false;
		if( gauss() ){
			// cout << endl;
			// for( int i=0; i<=D; ++i ){
				// for( int j=0; j<=D; ++j ){
					// cout << m[i][j] << " ";
				// }
				// cout << endl;
			// }
			// cout << endl << endl;
			// for( int i=0; i<=D; ++i ){
				// cout << b[i] << " ";
			// }
			// cout << endl << endl;
			ok = true;
			for( int i=0; i<=D; ++i ){
				if( abs( a[i] - floor(a[i]) ) > eps ){
					ok = false;
					break;
				}
				ua[i] = (ull)( a[i] + eps );
				if( ua[i] > 1000 || ua[i] < 0 ){
					ok = false;
					break;
				}
			}
			if( ok )
			for( int i=1; i<MX; ++i ){
				if( f(i) != d[i] ){
					ok = false;
					break;
				}
			}
		}
		if(ok){
			for( int i=0; i<a.size(); ++i ){
				if( i ) cout << " ";
				cout << ua[i];
			}
			cout << endl;
		}
		else{
			// for( int i=0; i<a.size(); ++i ){
				// if( i ) cout << " ";
				// cout << a[i];
			// }
			// cout << endl;
			cout << "This is a smart sequence!" << endl;
		}
		// cout << clock() << endl;
	}
}
