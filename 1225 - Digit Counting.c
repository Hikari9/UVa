/**
	UVa 1225 - Digit Counting
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.009s C
	O(nlog10n) time
*/
#include<stdio.h>
#include<stdlib.h>
int t,n,i;
div_t d;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int c[] = {0,0,0,0,0,0,0,0,0,0};
		for(i=1;i<=n;i++){
			d.quot = i;
			while(d.quot){
				d = div(d.quot,10);
				c[d.rem]++;
			}
		}
		for(i=0;i<9;i++) printf("%d ",c[i]);
		printf("%d\n",c[9]);
	}
}
