/**
	UVa 10870 - Recurrences
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.076s C++
	O(logn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long mat[16][16], f[16];
long long bas[16][16], power[16][16], temp[16][16], ans;
long long d, n, m;
long long i, j, k;

inline void multiply( long long res[16][16], long long a[16][16], long long b[16][16] ){
	for( i=0; i<d; ++i ){
		for( k=0; k<d; ++k ){
			res[i][k] = 0;
			for( j=0; j<d; ++j ){
				res[i][k] = ( res[i][k] + a[i][j]*b[j][k] )%m;
			}
		}
	}
}

inline void multiply( long long a[16][16], long long b[16] ){
	ans = 0;
	// for( i=0; i<d; ++i ){
		// res[i] = 0;
		for( j=0; j<d; ++j ){
			ans = ( ans + a[d-1][j] * b[j] )%m;
		}
	// }
}

void print( long long a[16][16] ){
	cout << "POWER:" << endl;
	for( i=0; i<d; ++i ){
		for( j=0; j<d; ++j ){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

long long matrix_pow(){
	memcpy( bas, mat, sizeof mat );
	memset( power, 0, sizeof power );
	for( i=0; i<d; ++i ) power[i][i] = 1;
	
	--n;
	while( n ){
		if( n&1 ){
			memcpy( temp, power, sizeof temp );
			multiply( power, bas, temp );
		}
		// print(power);
		// if( n>>=1 ){
			memcpy( temp, bas, sizeof temp );
			multiply( bas, temp, temp );
			n >>= 1;
		// }
	}
	
	// long long ANS[16];
	// multiply( ANS, power, f );
	// print(power);
	multiply(power,f);
	
	// cout << "ANS:" << endl;
	// for( i=0; i<d; ++i ){
		// cout << ANS[i] << endl;
	// }
	return ans;
}

int main(){
	for( i=1; i<16; ++i ) mat[i][i-1] = 1;
	d = 16;
	// print(mat);
	while( cin >> d >> n >> m, (d||m||n) ){
		for( i=0; i<d; ++i ){
			cin >> mat[0][i];
		}
		for( i=d-1; i>=0; --i ){
			cin >> f[i];
		}
		// print(mat);
		cout << matrix_pow() << endl;
		// printf( "%lld\n", matrix_pow() );
	}
}
