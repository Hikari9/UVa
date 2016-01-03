/**
	UVa 11428 - Cubes
	by Rico Tiongson
	Submitted: July 26, 2013
	Accepted 0.022s C++
	O(1) time + O(cbrt(n)^2) pregen
*/
#include<iostream>
#include<cstring>
using namespace std;
int n, i, j, k, ans[10001][2];
int cb[59];
int main(){
	for( i=0; i<59; ++i ) cb[i] = i*i*i;
	memset( ans, -1, sizeof ans );
	// 59^3 - 58^3 > 10000
	for( i=1; i<59; ++i ){
		for( j=i-1; j>0; --j ){
			k = cb[i] - cb[j];
			if( k > 10000 ) break;
			if( ans[k][0] == -1 ){
				ans[k][0] = i;
				ans[k][1] = j;
			}
			else{
				if( ans[k][1] > j ){
					ans[k][0] = i;
					ans[k][1] = j;
				}
			}
		}
	}
	while( cin >> n, n ){
		if( ans[n][0] == -1 ){
			cout << "No solution" << endl;
		}
		else{
			cout << ans[n][0] << ' ' << ans[n][1] << endl;
		}
	}
}
