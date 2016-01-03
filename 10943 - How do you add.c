/**
	UVa 10943 - How do you add?
	by Rico Tiongson
	Submitted: May 20, 2013
	Accepted 0.009s C
	O(n^2) pre-gen + O(1) time
*/
#include<stdio.h>
int n[101][101],i,j;
int main(){
	n[0][0] = 0;
	for(i=1;i<101;i++){
		n[i][0] = 0;
		n[0][i] = 1;
	}
	for(i=1;i<101;i++){
		for(j=1;j<101;j++){
			n[i][j] = (n[i-1][j]+n[i][j-1]);
			if(n[i][j]>999999) n[i][j]-=1000000;
		}
	}
	scanf("%d %d",&i,&j);
	while(i||j){
		printf("%d\n",n[i][j]);
		scanf("%d %d",&i,&j);
	}
}
