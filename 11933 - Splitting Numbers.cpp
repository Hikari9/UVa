/**
	UVa 11933 - Splitting Numbers
	by Rico Tiongson
	Submitted: September 5, 2013
	Accepted 0.012s C++
	O(logn) time
*/
#include<cstdio>
using namespace std;
unsigned n, x[2], m;
bool id;
int main(){
	while( scanf("%u",&n)==1 && n ){
		x[0] = x[1] = id = 0;
		m = 1;
		while(n>=m){
			if(n&m){
				x[id] |= m;
				id ^= 1;
			}
			m<<=1;
		}
		printf( "%u %u\n", x[0], x[1] );
	}
}
