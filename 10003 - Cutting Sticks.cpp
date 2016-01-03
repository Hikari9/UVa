/**
	UVa 10003 - Cutting Sticks
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.305s C++
	O(?) time
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 2147483647
using namespace std;
int l, n, i, c[85], a[65][65];
int dfs( int x, int y ){
	if( x+1 == y ) return 0;
	if( a[x][y] != -1 ) return a[x][y];
	int mn = INF;
	for( int j=x+1; j<y; ++j ){
		// cut the damn stick
		mn = min( c[y]-c[x]+dfs(x,j)+dfs(j,y), mn );
	}
	return a[x][y] = mn;
}
int main(){
	start:
		scanf("%d\n",&l);
		if(!l) return 0;
		memset( a, -1, sizeof a );
		scanf("%d\n",&n);
		if(!n){
			puts( "The minimum cutting is 0." );
			goto start;
		}
		c[0] = 0;
		for( i=1; i<=n; ++i ) scanf( "%d", c+i );
		c[++n] = l; // max offset
		printf("The minimum cutting is %d.\n",dfs(0,n));
	goto start;
}
