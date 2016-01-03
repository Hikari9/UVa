/**
	UVa 10608 - Friends
	by Rico Tiongson
	Submitted: May 27, 2013
	Accepted 0.042s C
	O(1n) time + O(nlogn) connect
*/
#include<stdio.h>
int f[30005],f2[30005],t,n,m,a,b,i;
int find(int x){
	if(f[x]==x) return x;
	else{
		f[x] = find(f[x]);
		return f[x];
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++){
			f[i] = i;
			f2[i] = 0;
		}
		while(m--){
			scanf("%d %d",&a,&b);
			f[find(a)] = find(b);
		}
		for(i=1;i<=n;i++)
			f2[find(i)]++;
		m = 0;
		for(i=1;i<=n;i++){
			if(f2[i]>m) m=f2[i];
		}
		printf("%d\n",m);
	}
}
