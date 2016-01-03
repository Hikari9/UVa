/**
	UVa 10074 - Take the Land
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.025s C++
	O(n^3) time
*/
#include<iostream>
#include<cstring>
#define INF 10000
using namespace std;
int a[101][101];
int n, m, i, j, k, sum[101], mx, Max, Sum;
int kadane(){
	Max = Sum = 0;
	for( k=0; k<m; ++k ){
		Sum += sum[k];
		if( Max < Sum )
			Max = Sum;
		if( Sum < 0 )
			Sum = 0;
	}
	return Max;
}
int main(){
	while( cin >> n >> m, n||m ){
		for( i=0; i<n; ++i ){
			for( j=0; j<m; ++j ){
				cin >> a[i][j];
				if( a[i][j] ) a[i][j] = -INF;
				else a[i][j] = 1;
			}
		}
		mx = 0;
		for( i=0; i<n; ++i ){
			memset( sum, 0, sizeof sum );
			for( j=i; j<n; ++j ){
				for( k=0; k<m; ++k ){
					sum[k] += a[j][k];
					// cout << sum[k] << " ";
				}
				// cout << endl;
				if( mx < kadane() )
					mx = Max;
			}
			// cout << endl;
		}
		cout << mx << endl;
	}
}
