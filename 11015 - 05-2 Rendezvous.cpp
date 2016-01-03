/**
	UVa 11015 - 05-2 Rendezvous
	by Rico Tiongson
	Submitted: July 7, 2013
	Accepted 0.015s C++
	O(n^3) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 33686018 // memset path
using namespace std;
int n, m, i, j, k, tc=0, mn, dest, cost[23][23];
char str[23][15];
void floydwarshall(){
	for( k=1; k<=n; ++k ){
		for( i=1; i<=n; ++i ){
			for( j=1; j<=n; ++j ){
				cost[i][j] = min( cost[i][j], cost[i][k] + cost[k][j] );
			}
		}
	}
	dest = 1;
	mn = INF;
	for( j=1; j<=n; ++j ){
		k = 0;
		for( i=1; i<=n; ++i ){
			k += cost[i][j];
		}
		// cout << j << ": " << k << endl;
		if( k<mn ){
			mn = k;
			dest = j;
		}
	}
}
int main(){
	test:
	scanf("%d %d", &n, &m);
	if( !n ) return 0; 
	for( i=1; i<=n; ++i ) scanf("%s",str[i]);
	memset( cost, 2, sizeof(cost) );
	for( i=1; i<=n; ++i ) cost[i][i] = 0;
	while( m-- ){
		scanf("%d %d %d", &i, &j, &k);
		cost[i][j] = cost[j][i] = min( cost[i][j], k );
	}
	floydwarshall();
	printf("Case #%d : %s\n", ++tc, str[dest] );
	goto test;
}
