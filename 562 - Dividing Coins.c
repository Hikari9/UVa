/**
	UVa 562 - Dividing Coins
	by Rico Tiongson
	Submitted: May 19, 2013
	Accepted 0.082s C
	O(n^2) time
*/
#include<stdio.h>
#include<string.h>
int ABS(int x){
	return x<0 ? -x : x;
}
int main(){
	const int mCoins = 100, mCents = 500,INF = 2147483647;
	const int mSum = mCoins * mCents;
	int ok[mSum+1],n,x,sum,t,i,j,mn;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(ok,0,sizeof(ok));
		ok[0]=1;
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			sum+=x;
			for(j=mSum-x;j>=0;j--){
				if(ok[j]) ok[j+x] = 1;
			}
			
		}
		mn = INF;
		for(i=0;i<=sum;i++){
			x = ABS(2*i-sum);
			if(ok[i] && x<mn){
				mn = x;
			}
		}
		printf("%d\n",mn);
	}
	return 0;
}
