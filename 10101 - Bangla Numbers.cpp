/**
	UVa 10101 - Bangla Numbers
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.026s C++
	O(5) time
*/
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long lag;
int r=0, i;
lag x;
const lag f[] = { 1000000000uLL, 10000000uLL, 100000uLL, 1000uLL, 100uLL };
const char* c[] = { "", "kuti", "lakh", "hajar", "shata" };
lag ans[5];
void print( lag z ){
	for( i=1; i<5; ++i ){
		ans[i] = z/f[i];
		z %= f[i];
	}
	for( i=1; i<5; ++i ){
		if( ans[i] )
		printf( " %lld %s", ans[i], c[i] );
	}
	if(z) printf(" %lld", z );
}
int main(){
	while( scanf("%lld",&x)!=EOF ){
		printf("%4d.",++r);
		if(!x) puts(" 0");
		else{
			if( x>f[0] ){
				print( (x/f[1]) );
				x%=f[1];
				putchar(' ');
				printf(c[1]);
			}
			print(x);
			putchar('\n');
		}
		
	}
}
