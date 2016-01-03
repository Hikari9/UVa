/**
	UVa 10363 - Tic Tac Toe
	by Rico Tiongson
	Submitted: July 25, 2013
	Accepted 0.015s ANSI C
	O(?) time
*/
#include<stdio.h>
#include<string.h>
char c[3][4], row[3], col[3];
int n, i, j, X, O, dot;
int win(){
	memset( row, '.', sizeof row );
	memset( col, '.', sizeof col );
	for( i=0; i!=3; ++i ){
		if( c[i][0]==c[i][1] && c[i][1]==c[i][2] ){
			row[i] = c[i][0];
		}
		if( c[0][i]==c[1][i] && c[1][i]==c[2][i] ){
			col[i] = c[0][i];
		}
	}
	if( (row[0]!='.') + (row[1]!='.') + (row[2]!='.') < 2 && (col[0]!='.') + (col[1]!='.') + (col[2]!='.') < 2 ){
		if( O+1==X ){
			for( i=0; i!=3; ++i ){
				if( row[i]=='O' ) return 0;
				if( col[i]=='O' ) return 0;
			}
			if( c[0][0]==c[1][1] && c[1][1]==c[2][2] && c[2][2]=='O' ) return 0;
			if( c[0][2]==c[1][1] && c[1][1]==c[2][0] && c[2][0]=='O' ) return 0;
		}
		else{
			for( i=0; i!=3; ++i ){
				if( row[i]=='X' ) return 0;
				if( col[i]=='X' ) return 0;
			}
			if( c[0][0]==c[1][1] && c[1][1]==c[2][2] && c[2][2]=='X' ) return 0;
			if( c[0][2]==c[1][1] && c[1][1]==c[2][0] && c[2][0]=='X' ) return 0;
		}
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d", &n);
	while( n ){
		scanf("%s%s%s",c[0],c[1],c[2]);
		X = O = dot = 0;
		for( i=0; i!=3; ++i ){
			for( j=0; j!=3; ++j ){
				switch( c[i][j] ){
					case 'X': ++X; break;
					case 'O': ++O; break;
					case '.': ++dot; break;
				}
			}
		}
		puts(( X+O+dot==9 && ( O==X || O+1==X ) && win() ) ? "yes" : "no");
		--n;
	}
}
