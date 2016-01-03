/**
	UVa 10465 - Homer Simpson
	by Rico Tiongson
	Submitted: June 14, 2013
	Accepted 0.026s C++
	O(t/n) time
*/
#include<stdio.h>
int m, n, t, b, c, beer, i, burg;
int main(){
	while( scanf("%d %d %d",&m,&n,&t )==3 ){
		if(m>n){
			i = m;
			m = n;
			n = i;
		}
		beer = m;
		for( b=t/n,c=t%n; b>=0; --b, c+=n ){
			i = c%m;
			if( i <= beer ){
				beer = i;
				burg = b+c/m;
			}
		}
		printf("%d",burg);
		if(beer) printf(" %d",beer);
		putchar('\n');
	}
}
