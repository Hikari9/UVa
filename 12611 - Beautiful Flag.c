/**
	UVa 12611 - Beautiful Flag
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.012s ANSI C
	O(4) time
*/
#include<stdio.h>
int t, i=0, r, n, e, s, w;
int main(){
	scanf("%d",&t);
	while( i<t ){
		getchar();
		scanf("%d",&r);
		printf("Case %d:\n",++i);
		n = (r*3)/2;
		s = -n;
		w = -(r*9)/4;
		e = (r*11)/4;
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", w, n, e, n, e, s, w, s);
	}
}
