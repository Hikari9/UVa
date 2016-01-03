/**
	UVa 305 - Joseph
	by Rico Tiongson
	Submitted: May 27, 2013
	Accepted 0.012s C
	O(1) time
*/
#include<stdio.h>
#include<string.h>
const char* c[15]={
	"","2","7","5","30","169","441","1872",
	"7632","1740","93313","459901",
	"1358657","2504881","13482720"
};
char b[5];
int n;
int main(){
	gets(b);
	n = atoi(b);
	while(n){
		puts(c[n]);
		gets(b);
		n = atoi(b);
	}
}
