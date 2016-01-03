/**
	UVa 10908 - Largest Square
	by Rico Tiongson
	Submitted: May 14, 2013
	Accepted 0.012s C
	O(n^2) time
*/
#include<stdio.h>
int t,m,n,q,i,j,l,dx[2],dy[2];
char c[105][105];
int track(int k){
	dx[0] = i-k;
	dx[1] = i+k;
	dy[0] = j-k;
	dy[1] = j+k;
	if( dx[0]<0 || dx[1]>=m || dy[0]<0 || dy[1]>=n ) return 2*k-1;
	for(l=dx[0];l<=dx[1];l++){
		if(c[l][dy[0]]!=c[i][j]) return 2*k-1;
		if(c[l][dy[1]]!=c[i][j]) return 2*k-1;
	}
	for(l=dy[0]+1;l<dy[1];l++){
		if(c[dx[0]][l]!=c[i][j]) return 2*k-1;
		if(c[dx[1]][l]!=c[i][j]) return 2*k-1;
	}
	return track(k+1);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d\n",&m,&n,&q);
		for(i=0;i<m;i++) gets(c[i]);
		printf("%d %d %d\n",m,n,q);
		while(q--){
			scanf("%d %d",&i,&j);
			printf("%d\n",track(1));
		}
	}
}
