/**
	UVa 12589 - Learning Vector
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.105s C++
	O(n^3) time
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MX 2501
using namespace std;
struct vect{
    int x, y;
	bool operator<( const vect& _ )const{
		return _.y * x < _.x * y;
	}
} v[51];
int t, tc=0, n, k, i, j, l, ysum, a[51][MX], h[MX], mx; // a[k][i] (k->number of picked vars) h-> current max height
int main() {
	scanf( "%d\n", &t );
	while( tc < t ){
		scanf( "%d %d\n", &n, &k );
		ysum = 0;
		for( i=0; i<n; ++i ){
			scanf("%d %d\n", &v[i].x, &v[i].y );
			ysum += v[i].y;
		}
		sort( v, v+n );
		
		memset( a, 0, sizeof a );
		a[0][0] = 1; // offset
		memset( h, 0, sizeof h );
		for( i=0; i<k; ++i ){
			for( j=i; j>=0; --j ){
				// knapsack pick id
				for( l=min( h[j], ysum-v[i].y ); l>=0; --l ){
					// track back
					if( a[j][l] ){
						a[j+1][ l+v[i].y ] = max( a[j+1][l+v[i].y], a[j][l] + 2 * l * v[i].x + v[i].x * v[i].y );
						h[j+1] = max( h[j+1], l+v[i].y );
					}
				}
			}
		}
		// for i>=k
		for( ; i<n; ++i ){
			for( j=k-1; j>=0; --j ){
				// knapsack pick id
				for( l=min( h[j], ysum-v[i].y ); l>=0; --l ){
					// track back
					if( a[j][l] ){
						a[j+1][ l+v[i].y ] = max( a[j+1][l+v[i].y], a[j][l] + 2 * l * v[i].x + v[i].x * v[i].y );
						h[j+1] = max( h[j+1], l+v[i].y );
					}
				}
			}
		}
		mx = 0;
		for( i=0; i<=ysum; ++i ) mx = max( mx, a[k][i] );
		printf("Case %d: %d\n",++tc,mx-1);
	}
}
