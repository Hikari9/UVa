/**
	UVa 11760 - Brother Arif, Please feed us!
	by Rico Tiongson
	Submitted: September 6, 2013
	Accepted 0.028s C++
	O(5) time
*/
#include<cstdio>
#include<cstring>
#define yes "Escaped again! More 2D grid problems!"
#define no "Party time! Let's find a restaurant!"
using namespace std;
int r, c, n, tc;
int x, y, i;
bool R[10001], C[10001], found;
int main(){
	while( scanf( "%d %d %d", &r, &c, &n )==3 && (r||c||n) ){
		memset( R, 0, sizeof R );
		memset( C, 0, sizeof C );
		while(n--){
			scanf( "%d %d", &x, &y );
			R[x] = true;
			C[y] = true;
		}
		scanf( "%d %d", &x, &y );
		printf( "Case %d: ", ++tc );
		if( (!R[x]&&!C[y])||(x>0&&!R[x-1]&&!C[y])||(x<r-1&&!R[x+1]&&!C[y])||(y>0&&!R[x]&&!C[y-1])||(y<c-1&&!R[x]&&!C[y+1]) ) puts(yes);
		else puts(no);
	}
}
