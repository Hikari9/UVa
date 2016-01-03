/**
	UVa 983 - Localized Summing for Blurring
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.296s C++
	O(n^2) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef unsigned long long lag;

int n, m;
lag mat[1002][1002];
lag row[1002][1002], col[1002][1002], total;
bool first = true;

void print( lag ar[1002][1002] ){
	for( int i=1; i<=n; ++i ){
		for( int j=1; j<=n; ++j ){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	while( fscanf( stdin, "%d %d", &n, &m ) != EOF ){
		if( !first ) putchar( '\n' );
		else first = false;
		total = 0;
		for( int i=1; i<=n; ++i ){
			for( int j=1; j<=n; ++j ){
				int x;
				fscanf( stdin, "%d", &x );
				mat[i][j] = x;
				row[i][j] = x + row[i-1][j];
				col[i][j] = x + col[i][j-1];
			}
		}
		
		// print( mat );
		// cout << "R: " << endl;
		// print( row );
		// cout << "C: " << endl;
		// print( col );
		
		lag moving_sum = 0;
		for( int i=1; i<m; ++i ){
			moving_sum += col[i][m];
		}
		for( int i=m; i<=n; ++i ){
			// cout << i << " " << m << endl;
			moving_sum = moving_sum - col[i-m][m] + col[i][m];
			// cout << "MOVE: " << moving_sum << endl;
			lag sum = moving_sum - ( row[i][m] - row[i-m][m] );
			// cout << "MOVE: " << moving_sum << endl;
			for( int j=m; j<=n; ++j ){
				// cout << "SUM: " << i << " " << j << endl;
				// cout << row[i][j-1] << " " << row[i-m][j-m] << endl;
				sum = sum - ( row[i][j-m] - row[i-m][j-m] ) + ( row[i][j] - row[i-m][j] );
				fprintf( stdout, "%lld\n", sum );
				total += sum;
			}
		}
		fprintf( stdout, "%lld\n", total );
	}
}
