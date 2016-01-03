/**
	UVa 11956 - Brainfuck
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.162s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int led[100], *p, t, i, C=0;
char buf[100005];
int main(){
	scanf("%d", &t );
	while( C < t ){
		p = led;
		memset( led, 0, sizeof(led) );
		scanf( "%s", buf );
		printf("Case %d:", ++C );
		for( i=0; buf[i]; ++i ){
			switch( buf[i] ){
				// case '.':
					// out[ p-led ] = true;
					// break;
				case '>':
					if( ++p==led+100 ) p=led;
					break;
				case '<':
					if( p==led ) p = led+99;
					else --p;
					break;
				case '+':
					if( ++(*p) == 256 ) *p = 0;
					break;
				case '-':
					if( --(*p) == -1 ) *p = 255;
					break;
			}
		}
		for( i=0; i<100; ++i ){
			// if( out[i] )
			printf(" %02X", led[i]);
			// else printf(" 00");
		}
		putchar('\n');
	}
}
