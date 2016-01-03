/**
	UVa 12531 - Hours and Minutes
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.015s C++
	O(1) time
*/
#include<cstdio>
using namespace std;
int n;
int main(){
	while( scanf( "%d", &n )==1 ){
		if( n%6==0 ) puts("Y");
		else puts("N");
	}
}
