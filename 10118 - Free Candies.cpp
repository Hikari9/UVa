/**
	UVa 10118 - Free Candies
	by Rico Tiongson
	Submitted: June 14, 2013
	Accepted 0.172s C++
	O(?) time
*/
#include<cstdio>
#include<cstring>
#define STATE state[ top[0] ][ top[1] ][ top[2] ][ top[3] ]
int n, i, a[4][41], top[4], state[41][41][41][41], mx;
bool u[21];
int dfs( int d ){
	int mx=0, I;
	if( STATE == -1 ){
		if( d==5 ) STATE = 0;
		else{
			for( int j=0; j<4; ++j ){
				if( top[j]<n ){
					u[ a[j][top[j]] ]^=true;
					if( u[ a[j][top[j] ] ] ){
						++top[j];
						I = dfs(d+1);
					}
					else{
						++top[j];
						I = dfs( d-1 )+1;
					}
					u[ a[j][--top[j]] ] ^= true;
					if( I > mx ) mx = I;
				}
			}
		}
		STATE = mx;
	}
	return STATE;
}
int main(){
	scanf("%d",&n);
	while( n ){
		getchar();
		memset(u,0,sizeof(u));
		memset(top,0,sizeof(top));
		memset(state,-1,sizeof(state));
		for( i=0; i<n; ++i ){
			scanf("%d %d %d %d",a[0]+i,a[1]+i,a[2]+i,a[3]+i);
			getchar();
		}
		printf("%d\n", dfs(0));
		scanf("%d",&n);
	}
}
