/**
	UVa 10689 - Yet another Number Sequence
	by Rico Tiongson
	Submitted: September 14, 2013
	Accepted 0.182s C++
	O(n^3logn) time
*/
#include<iostream>
#include<cstdio>
#include<stdexcept>
#include<algorithm>
#define mx 15001
using namespace std;
int t, a, b, n, m;
int mod[5] = { 1, 10, 100, 1000, 10000 };
struct matrix;
ostream& operator<<( ostream&, const matrix& );
struct matrix{
	int ** a;
	int p, q;
	matrix(): a(NULL), p(0), q(0) {}
	int* operator[]( size_t pos )const{ return a[pos]; }
	matrix( const matrix& x ): a( new int*[x.p] ), p(x.p), q(x.q) {
		int i, j;
		for( i=0; i<x.p; ++i ){
			a[i] = new int[x.q];
			for( j=0; j<x.q; ++j ){
				a[i][j] = x[i][j];
			}
		}
	}
	matrix& operator=( const matrix& x ){
		int i, j;
		for( i=0; i<p; ++i ){
			delete[] a[i];
		}
		delete[] a;
		p = x.p;
		q = x.q;
		a = new int*[p];
		for( i=0; i<p; ++i ){
			a[i] = new int[q];
			for( j=0; j<q; ++j ){
				a[i][j] = x[i][j];
			}
		}
		return *this;
	}
	// matrix( int P, int Q ): a( new int*[P] ), p(P), q(Q){
		// for( int i=0; i<P; ++i )
			// a[i] = new int[Q];
	// }
	matrix( int P, int Q, int f=int() ): a( new int*[P] ), p(P), q(Q){
		int i, j;
		for( i=0; i<P; ++i ){
			a[i] = new int[Q];
			for( j=0; j<Q; ++j ){
				a[i][j] = f;
			}
		}
	}
	~matrix(){
		for( int i=0; i<p; ++i ) delete[] a[i];
		delete[] a;
	}
	matrix operator*( const matrix& b )const{
		if( q != b.p )
			throw logic_error( "cannot multiply matrices" );
		matrix ans( p, b.q );
		int i, j, k;
		for( i=0; i<p; ++i ){
			for( j=0; j<b.q; ++j ){
				ans[i][j] = 0;
				for( k=0; k<q; ++k ){
					ans[i][j] = ( ans[i][j] + ( a[i][k] * b[k][j] )%mod[m] )%mod[m];
				}
			}
		}
		return ans;
	}
	matrix pow( int expo ) const{
		if( p!=q )
			throw logic_error( "matrix should be square" );
		matrix ans( p, p );
		for( int i=0; i<p; ++i ) ans[i][i] = 1;
		matrix bas( *this );
		while( expo ){
			if( expo&1 )
				ans = ans*bas;
			bas = bas*bas;
			expo >>= 1;
		}
		return ans;
	}
};
ostream& operator<<( ostream& out, const matrix& _ ){
	for( int i=0; i<_.p; ++i ){
		for( int j=0; j<_.q; ++j ){
			out << _[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
matrix x(2,1), y(2,2);

int main(){
	y[0][0] = y[0][1] = y[1][0] = 1;
	y[1][1] = 0;
	scanf( "%d", &t );
	while(t--){
		scanf( "%d %d %d %d", &a, &b, &n, &m );
		// if(n==0){
			// printf( "%d\n", a%mod[m] );
			// continue;
		// }
		// if(n==1){
			// printf( "%d\n", b%mod[m] );
			// continue;
		// }
		x[0][0] = b;
		x[1][0] = a;
		
		printf( "%d\n", (y.pow(n)*x)[1][0]%mod[m] );
	}
}
