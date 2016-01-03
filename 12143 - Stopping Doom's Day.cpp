/**
	UVa 12143 - Stopping Doom's Day
	by Rico Tiongson
	Submitted: September 3, 2013
	Accepted 0.015s C++
	O(5) time
*/
#include<cstdio>
#define mod 10007
using namespace std;
typedef long long lag;
lag f[] = { 1652LL, -3927LL, 5995LL, -781LL, 7068LL }, sum;
int i, n, b;
int main(){
	while( scanf("%d",&n)==1 && n ){
		sum = 0;
		n %= mod;
		b = n = (n*n)%mod;
		for( i=0; i<5; ++i ){
			sum = ( sum + f[i]*b )%mod;
			b = (b*n)%mod;
		}
		printf( "%lld\n", sum );
	}
}
