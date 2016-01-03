/**
	UVa 11850 - Alaska
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.016s C++
	O(~3000) time
*/
#include<cstdio>
#include<cstring>

bool a[1423];
int n, i, cur;
bool calc(){
	for( i=0, cur=0; i<1423; ++i, ++cur ){
		if( a[i] ){
			if( cur>200 ) return false;
			cur = 0;
		}
	}
	for( i=1422; i>=0; --i, ++cur ){
		if( a[i] ){
			if( cur>200 ) return false;
			cur = 0;
		}
	}
	return true;
}
int main(){
	scanf("%d", &n);
	while( n ){
		memset( a, 0, sizeof( a ) );
		do{
			scanf("%d", &i);
			a[i] = true;
		} while( --n );
		if( calc() ) puts("POSSIBLE");
		else puts("IMPOSSIBLE");
		scanf("%d", &n);
	}
}
