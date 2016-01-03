/**
	UVa 10049 - Self-describing Sequence
	by Rico Tiongson
	Submitted: September 15, 2013
	Accepted 0.032s C++
	O(O(n)) time
*/
#include<iostream>
#include<vector>
#define lim 673368
using namespace std;
long long f[lim] = { 1, 1, 2, 2 };
long long i, j, x, sz=4;
long long cur, bound, n;
int main(){
	for( i=3; sz<lim; ++i ){
		for( j=0; j<f[i] && sz<lim; ++j ){
			f[sz++] = i;
		}
	}
	while( cin >> n, n ){
		if( n<lim ){
			cout << f[n] << endl;
			continue;
		}
		x = 3;
		cur = 4;
		bound = 6;
		while( bound+x*f[x] < n ){
			bound += x*f[x];
			cur += f[x];
			++x;
		}
		cout << ( cur + (n-bound)/x ) << endl;
	}
}
