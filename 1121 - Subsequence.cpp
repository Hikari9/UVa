/**
	UVa 1121 - Subsequence
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.092s C++
	O(n) time
*/
#include<iostream>
#define INF 2147483647
using namespace std;
int n, s, i, j, mn, sum;
int a[100002];
int main(){
	while( cin >> n >> s ){
		for( i=0; i<n; ++i ) cin >> a[i];
		j = sum = 0;
		mn = INF;
		for( i=0; i<n; ++i ){
			while( sum<s && j<n )
				sum += a[j++];
			if( sum>=s ) mn = min(mn,j-i);
			sum -= a[i];
		}
		if( mn==INF ) cout << "0" << endl;
		else cout << mn << endl;
	}
}
