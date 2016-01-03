/**
	UVa 11470 - Square Sums
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.019s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int n, n2, i, j, sum, tc=0;
int sq[11][11];
int main(){
	while( cin >> n, n ){
		n2 = n/2;
		for( i=0; i<n; ++i ){
			for( j=0; j<n; ++j ){
				cin >> sq[i][j];
			}
		}
		cout << "Case " << ++tc << ':';
		for( i=0; i<n2; ++i ){
			sum = 0;
			// across
			for( j=i; j<n-i; ++j ){
				sum += sq[i][j];
				sum += sq[n-i-1][j];
			}
			// down
			for( j=i+1; j<n-i-1; ++j ){
				sum += sq[j][i];
				sum += sq[j][n-i-1];
			}
			cout << ' ' << sum;
		}
		// gitna
		if( n%2 ){
			cout << ' ' << sq[n2][n2];
		}
		cout << endl;
	}
}
