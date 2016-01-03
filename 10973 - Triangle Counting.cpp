/**
	UVa 10973 - Triangle Counting
	by Rico Tiongson
	Submitted: June 15, 2013
	Accepted 1.119s C++
	O(n^3) time
*/
#include<cstdio>
#include<cstring>
int t, r, n, m, x, y, c, i, j, k;
bool a[3005][3005];
int main(){
	scanf("%d",&t);
	while( t ){
		getchar();
		scanf("%d %d",&n, &m);
		memset(a,0,sizeof(a));
		while( m ){
			getchar();
			scanf("%d %d",&x,&y);
			if(x<y) a[x][y] = true;
			else a[y][x] = true;
			--m;
		}
		c = 0;
		for( i=1; i<=n; ++i ){
			for( j=i+1; j<=n; ++j ){
				if( a[i][j] ){
					for( k=j+1; k<=n; ++k ){
						if( a[i][k] && a[j][k] ){
							++c;
						}
					}
				}
			}
		}
		printf("%d\n",c);
		--t;
	}
}
