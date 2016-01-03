/**
	UVa 12537 - Radiation
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.215s C++
	O(nlogn) time
*/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long lag;
int x[200001], y[200001], n, i, tc;
int ax, ay, bx, by, q;
lag R1, R2;
lag dx, dy;
lag d1[200001], d2[200001];
int main(){
	while( scanf( "%d", &n )==1 ){
		if(!n) break;
		for( i=0; i<n; ++i )
			scanf( "%d %d", x+i, y+i );
		scanf( "%d %d %d %d %d", &ax, &ay, &bx, &by, &q );
		for( i=0; i<n; ++i ){
			dx = ax - x[i];
			dy = ay - y[i];
			d1[i] = dx*dx + dy*dy;
			dx = bx - x[i];
			dy = by - y[i];
			d2[i] = dx*dx + dy*dy;
		}
		sort( d1, d1+n );
		sort( d2, d2+n );
		printf( "Case %d:\n", ++tc );
		while(q--){
			scanf( "%lld %lld", &R1, &R2 );
			printf( "%d\n", max(0,(int)( d2+n-upper_bound(d2,d2+n,R2*R2) ) - (int)(upper_bound(d1,d1+n,R1*R1)-d1)) );
		}
	}
}
