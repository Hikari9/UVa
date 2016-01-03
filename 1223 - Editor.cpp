#include<stdio.h>
#include<string.h>
int ra[5001][5001], n, len, mx, i, j;
char buf[5001];
int main(){
	scanf("%d\n",&n);
	while( n ){
		gets( buf );
		len = strlen( buf )+1;
		mx = 0;
		// bottom-up lcs
		for( i=1; i<len; ++i ){
			for( j=1; j<len; ++j ){
				if( buf[i-1] == buf[j-1] && i!=j ){
					ra[i][j] = ra[i-1][j-1] + 1;
					if( mx<ra[i][j] ) mx = ra[i][j];
				}
				else ra[i][j] = 0;
			}
		}
		printf("%d\n",mx);
		--n;
	}
}
