/**
	UVa 12602 - Nice Licence Plates
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.006s ANSI C
	O(1) time
*/
#include<stdio.h>
#include<stdlib.h>
int n,x;
char s[5];
int main(){
	scanf("%d",&n);
	while(n--){
		getchar();
		s[0] = getchar();
		s[1] = getchar();
		s[2] = getchar();
		getchar();
		scanf("%d",&x);
		if(abs((s[0]-'A')*676 + (s[1]-'A')*26 + (s[2]-'A')-x)<101) puts("nice");
		else puts("not nice");
	}
}
