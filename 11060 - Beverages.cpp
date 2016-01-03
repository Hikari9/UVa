/**
	UVa 11060 - Beverages
	by Rico Tiongson
	Submitted: July 7, 2013
	Accepted 0.016s C++
	O(?) time
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int i, j, n, m, r=0, a, b, in[101];
char buf[2][55];
char str[101][55];
bool adj[101][101], vis[101], found;
map<string,int> id;
int main(){
	while( scanf("%d", &n)==1 ){
		id.clear();
		for( i=0; i<n; ++i ){
			scanf("%s",str[i]);
			id[ str[i] ] = i;
		}
		memset( adj, 0, sizeof( adj ) );
		memset( in, 0, sizeof( in ) );
		memset( vis, 0, n );
		scanf("%d", &m);
		while( m-- ){
			scanf("%s %s",buf[0],buf[1]);
			i = id[ buf[0] ];
			j = id[ buf[1] ];
			if( i!=j && !adj[i][j] ){
				adj[i][j] = true;
				++in[j];
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:",++r);
		do{
			found = true;
			for( i=0; i<n; ++i ){
				if( !vis[i] && !in[i] ){
					found = false;
					vis[i] = true;
					printf(" %s", str[i] );
					for( j=0; j<n; ++j ){
						// implies no cycles
						if( adj[i][j] /* && !vis[i] */ ) --in[j];
					}
					i = -1;
				}
			}
		} while( !found );
		puts(".\n");
	}
}
