/**
	UVa 825 - Walking on the Safe Side
	by Rico Tiongson
	Submitted: July 7, 2013
	Accepted 0.022s C++
	O(?) time
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
int t, w, n, i, ww, c;
bool adj[1001][1001];
char buf[10005], *p;
void dfs( int x, int y, int moves ){
	if( x>w || y>n ) return;
	if( adj[x][y] ) return;
	if( moves==ww ){
		++c;
		return;
	}
	dfs( x+1, y, ++moves );
	dfs( x, y+1, moves );
}
int main(){
	scanf("%d",&t);
	while( t ){
		scanf("%d %d",&w,&n);
		memset( adj, 0, sizeof( adj ) );
		for( i=0; i<w; ++i ){
			scanf("%d",&ww);
			gets(buf);
			p = strtok( buf, " " );
			while( p != NULL ){
				adj[ww][atoi(p)] = true;
				p = strtok( NULL, " " );
			}
		}
		ww = w+n-2;
		c = 0;
		dfs( 1, 1, 0 );
		printf("%d\n", c );
		if( --t ) putchar('\n');
	}
}
