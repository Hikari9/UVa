/**
	UVa 11525 - Permutation
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 2.682s C++
	O(n^2) time
*/
// #include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t, k, i, Si;
vector<int> v;
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d", &k );
		v.clear();
		for( i=1; i<=k; ++i ) v.push_back(i);
		for( i=0; i<k; ++i ){
			scanf( "%d", &Si );
			if(i) putchar( ' ' );
			printf( "%d", v[Si] );
			v.erase( v.begin()+Si );
		}
		putchar('\n');
	}
}
