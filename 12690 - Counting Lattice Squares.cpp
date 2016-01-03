/**
	UVa 12690 - Counting Lattice Squares
	by Rico Tiongson
	Submitted: December 7, 2013
	Accepted 0.052s C++
	O(n) pre-gen + O(1) time
*/
#include <iostream>
#include <cstdio>
#include <climits>
#define MX 100001
using namespace std;
typedef unsigned long long lag;

int n, m, id;
lag i1[MX], i2[MX], i3[MX];
lag N, M;

int main(){
	for( int i=1; i<MX; ++i ){
		i1[i] = i1[i-1];
		i2[i] = i2[i-1];
		i3[i] = i3[i-1];
		if( (i&1) == 1 ){
			i1[i] += i;
			i2[i] += (lag)i*i;
			i3[i] += (lag)i*i*i;
		}
	}
	while( scanf( "%d %d", &n, &m ) == 2 && (n || m) ){
		N = n+1;
		M = m+1;
		id = min( n, m );
		printf( "%llu\n", i3[id] - i2[id] * (N+M) + i1[id] * N * M );
	}
}
