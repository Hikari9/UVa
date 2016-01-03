/**
	UVa 11459 - Snakes and Ladders
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.236s ANSI C
	O(n) time
*/
#include<stdio.h>
#include<string.h>
int t, a, b, c, x, y, p[1000005], g[105], game;
int main(){
	scanf("%d",&t);
	while( t-- ){
		scanf("%d %d %d",&a,&b,&c);
		for( x=0; x<a; ++x ) p[x] = 1;
		memset( g, 0, sizeof( g ) );
		while( b-- ){
			scanf("%d %d", &x, &y);
			g[x] = y;
		}
		game = 1;
		for( x=0; c; ++x, --c ){
			if( x==a ) x=0;
			scanf("%d",&y);
			if( game ){
				p[x] += y;
				if( p[x]<100 ){
					if( g[ p[x] ] ) p[x] = g[ p[x] ];
				}
				if( p[x]>=100 ){
					p[x] = 100;
					game = 0;
				}
			}
		}
		for( x=0; x<a; ++x ){
			printf("Position of player %d is %d.\n", x+1, p[x] );
		}
	}
}
