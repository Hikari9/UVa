/**
	UVa 11360 - Have Fun with Matrices
	by Rico Tiongson
	Submitted: July 10, 2013
	Accepted 0.012s ANSI C
	O(n^2) time
*/
#include<stdio.h>
char M[11][11], cmd[15], temp;
int i, j, t, n, m, a, b, tc=0;
int main(){
	scanf("%d", &t);
	while( tc<t ){
		scanf("%d",&n);
		for( i=0; i<n; ++i ){
			scanf("%s",M[i]);
		}
		scanf("%d",&m);
		while( m-- ){
			scanf("%s", cmd);
			switch( cmd[0] ){
				case 'r':
					getchar();
					a = getchar()-'1';
					getchar();
					b = getchar()-'1';
					for( j=0; j<n; ++j ){
						temp = M[a][j];
						M[a][j] = M[b][j];
						M[b][j] = temp;
					}
					
					break;
				case 'c':
					getchar();
					a = getchar()-'1';
					getchar();
					b = getchar()-'1';
					for( i=0; i<n; ++i ){
						temp = M[i][a];
						M[i][a] = M[i][b];
						M[i][b] = temp;
					}
					break;
				case 'i':
					for( i=0; i<n; ++i ){
						for( j=0; j<n; ++j ){
							if( ++M[i][j] == ':' ) M[i][j] = '0';
						}
					}
					break;
				case 'd':
					for( i=0; i<n; ++i ){
						for( j=0; j<n; ++j ){
							if( --M[i][j] == '/' ) M[i][j] = '9';
						}
					}
					break;
				case 't':
					for( i=0; i<n; ++i ){
						for( j=0; j<i; ++j ){
							temp = M[i][j];
							M[i][j] = M[j][i];
							M[j][i] = temp;
						}
					}
					break;
			}
		}
		printf("Case #%d\n", ++tc);
		for( i=0; i<n; ++i ){
			for( j=0; j<n; ++j ){
				putchar( M[i][j] );
			}
			putchar('\n');
		}
		putchar('\n');
	}
}
