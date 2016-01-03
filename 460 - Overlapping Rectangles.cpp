/**
	UVa 460 - Overlapping Rectangles
	by Rico Tiongson
	Submitted: July 2, 2013
	Accepted 0.012s C++
	O(logn) time
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int t, x[4], y[4];
int main(){
	scanf("%d", &t);
	while( t ){
		scanf("%d %d %d %d", x, y, x+1, y+1 );
		scanf("%d %d %d %d", x+2, y+2, x+3, y+3 );
		if( x[1]<=x[2] || y[1]<=y[2] || x[3]<=x[0] || y[3]<=y[0] ){
			puts("No Overlap");
		}
		else{
			sort( x, x+4 );
			sort( y, y+4 );
			printf( "%d %d %d %d\n", x[1], y[1], x[2], y[2] );
		}
		if(--t) putchar('\n');
	}
}
