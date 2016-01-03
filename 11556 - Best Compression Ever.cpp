/**
	UVa 11556 - Best Compression Ever
	by Rico Tiongson
	Submitted: october 29, 2013
	Accepted 0.012s C++
	O(1) time
*/
#include<cstdio>
using namespace std;
long long n;
int b;
int main(){
	while( scanf( "%lld %d", &n, &b ) == 2 ){
		if( n < (1LL << (b+1)) ) puts("yes");
		else puts("no");
	}
}
