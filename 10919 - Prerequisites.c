/**
	UVa 10919 - Prerequisites
	by Rico Tiongson
	Submitted: October 19, 2013
	Accepted 0.048s ANSI C
	O(n) time
*/
#include<stdio.h>
#include<string.h>

char ok[10000];
int k, m, c, r, i, j, x, cnt, yes;

int main(){
	while( scanf("%d", &k) == 1 && k ){
		scanf("%d", &m);
		memset( ok, 0, sizeof ok );
		for( i=0; i<k; ++i ){
			scanf("%d", &x);
			ok[x] = 1;
		}
		yes = 0;
		for( i=0; i<m; ++i ){
			cnt = 0;
			scanf("%d %d", &c, &r);
			for( j=0; j<c; ++j ){
				scanf("%d", &x);
				if( ok[x] ) ++cnt;
			}
			if( cnt >= r ) ++yes;
		}
		if( yes == m ) puts("yes");
		else puts("no");
	}
}
