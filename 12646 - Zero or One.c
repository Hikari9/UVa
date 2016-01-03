/**
	UVa 12646 - Zero or One
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.012s ANSI C
	O(1) time
*/
#include<stdio.h>
char buf[6];
int main(){
	while(gets(buf)){
		puts( buf[0]==buf[2] ? ( buf[0]!=buf[4] ? "C" : "*" ) : ( buf[0]==buf[4] ? "B" : "A" ) );
	}
}
