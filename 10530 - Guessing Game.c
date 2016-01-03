/**
	UVa 10530 - Guessing Game
	by Rico Tiongson
	Submitted: May 14, 2013
	Accepted 0.012s C
	O(11) time
*/
#include<stdio.h>
#include<string.h>
int main(){
	int n,x[11],ok,i,temp;
	char c[11];
	while(1){
		memset(x,0,sizeof(x));
		scanf("%d",&n);
		if(!n) return 0;
		getchar();
		gets(c);
		ok=1;
		while(c[0]!='r'){
			temp = (c[4]=='h'?1:-1);
			if(x[n]!=0 && temp!=x[n]) ok = 0;
			else x[n] = temp;
			scanf("%d\n",&n);
			gets(c);
		}
		if(ok){
			for(i=n;i>0;i--){
				if(x[i]==1){
					ok = 0;
					break;
				}
			}
		}
		if(ok){
			for(i=n;i<11;i++){
				if(x[i]==-1){
					ok = 0;
					break;
				}
			}
		}
		if(ok) puts("Stan may be honest");
		else puts("Stan is dishonest");
	}
}
