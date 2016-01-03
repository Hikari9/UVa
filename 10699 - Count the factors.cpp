/**
	UVa 10699 - Count the Factors
	by Rico Tiongson
	Submitted: August 28, 2013
	Accepted 0.038s C++
	O(nloglogn) pregen
*/
#include<cstdio>
using namespace std;
int pr[1000001], i, j, x;
char buf[8];
int main(){
	pr[2] = 1;
	for( j=4; j<1000001; j+=2 ) ++pr[j];
	for( i=3; i<1000001; i+=2 ){
		if( !pr[i] ){
			for( j=i; j<1000001; j+=i ) ++pr[j];
		}
	}
	while( scanf( "%d", &x )==1 ){
		if( !x ) return 0;
		printf( "%d : %d\n", x, pr[x] );
	}
}
