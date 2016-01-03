/**
	UVa 11230 - Annoying painting tool
	by Rico Tiongson
	Submitted: August 5, 2013
	Accepted 0.056s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int n, m, r, c, i, j, I, J, k, l, ans;
char a[105][105];
int main(){
	while( cin >> n >> m >> r >> c, n||m||r||c ){
		for( i=0; i<n; ++i ){
			cin >> a[i];
			for( j=0; j<m; ++j ) a[i][j] -= '0';
		}
		I = n-r+1;
		J = m-c+1;
		ans = 0;
		for( i=0; i<I; ++i ){
			for( j=0; j<J; ++j ){
				if( a[i][j] ){
					for( l=0; l<r; ++l ){
						for( k=0; k<c; ++k ){
							a[i+l][j+k] ^= true;
						}
					}
					++ans;
				}
			}
		}
		for( i=0; i<n; ++i ){
			for( j=0; j<m; ++j ){
				if( a[i][j] ){
					ans = -1;
					goto breaker;
				}
			}
		}
		breaker:
			cout << ans << endl;
	}
}
