/**
	UVa 10323 - Factorial! You Must be Kidding!!!
	by Rico Tiongson
	Submitted: May 18, 2013
	Accepted 0.022s C++
	O(4) time
*/
#include<cstdio>
unsigned long long f[14]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};
int x;
int main(){
	while(scanf("%d",&x)!=EOF){
		if(x<0){
			if(x%2==-1) puts("Overflow!");
			else puts("Underflow!");
		}
		else if(x>13) puts("Overflow!");
		else if(x<8) puts("Underflow!");
		else printf("%lld\n",f[x]);
	}
}
