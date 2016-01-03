/**
	UVa 11936 - The Lazy Lumberjacks
	by Rico Tiongson
	Submitted: June 16, 2013
	Accepted 0.013s ANSI C
	O(3) time
*/
#include<stdio.h>
int n, a, b, c;
int main(){
	scanf("%d",&n);
	while( n ){
		getchar();
		scanf("%d %d %d",&a,&b,&c);
		if( a<1 || b<1 || c<1 ) puts("Wrong!!");
		else if( a>b ){
			if( a>c ) puts( (a<b+c) ? "OK" : "Wrong!!" );
			else puts( (c<a+b) ? "OK" : "Wrong!!" );
		}
		else if( b>c ) puts( (b<a+c) ? "OK" : "Wrong!!" );
		else puts( (c<a+b) ? "OK" : "Wrong!!" );
		--n;
	}
}
