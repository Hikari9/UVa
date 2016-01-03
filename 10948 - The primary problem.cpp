/**
	UVa 10948 - The primary problem
	by Rico Tiongson
	Submitted: September 14, 2013
	Accepted 0.019s C++
	O(nloglogn) pregen + O(nloglogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define mx 1000001
using namespace std;
bool isPr[mx];
vector<int> pr;
int n;
long long i, j;
int main(){
	memset( isPr, 1, sizeof isPr );
	isPr[0] = isPr[1] = 0;
	pr.push_back(2);
	for( j=4; j<mx; j+=2 )
		isPr[j] = 0;
	for( i=3; i<mx; i+=2 ){
		if( isPr[i] ){
			pr.push_back(i);
			for( j=i*i; j<mx; j+=i )
				isPr[j] = 0;
		}
	}
	while( scanf( "%d", &n )==1 ){
		if(!n) break;
		printf( "%d:\n", n );
		if(n==1){
			puts("NO WAY!");
			continue;
		}
		if( n&1 ){
			// only two
			if( isPr[n-2] )
				printf( "2+%d\n", n-2 );
			else
				puts("NO WAY!");
		}
		else{
			for( i=0; i<pr.size() && (pr[i]<<1) <= n; ++i ){
				if( isPr[n-pr[i]] ){
					printf( "%d+%d\n", pr[i], n-pr[i] );
					goto end;
				}
			}
			puts("NO WAY!");
		}
		end:;
	}
}
