/**
	UVa 11456 - Trainsorting
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.013s C++
	O(nlogn) time
*/
#include<cstdio>
#include<functional>
#include<algorithm>
#define MX 2001
using namespace std;
int t, n, i, j, a[MX], seq[MX], sz;
int lis[MX], lds[MX], mx;
int main(){
	scanf( "%d", &t );
	while(t--){
		scanf( "%d", &n );
		for( i=0; i<n; ++i )
			scanf( "%d", a+i );
		sz = 0;
		for( i=n-1; i>=0; --i ){
			j = lower_bound( seq, seq+sz, a[i] ) - seq;
			if( j==sz ){
				seq[sz++] = a[i];
				lds[i] = sz;
			}
			else{
				seq[j] = a[i];
				lds[i] = j+1;
			}
		}
		sz = 0;
		for( i=n-1; i>=0; --i ){
			j = lower_bound( seq, seq+sz, a[i], greater<int>() ) - seq;
			if( j==sz ){
				seq[sz++] = a[i];
				lis[i] = sz;
			}
			else{
				seq[j] = a[i];
				lis[i] = j+1;
			}
		}
		mx = 0;
		for( i=0; i<n; ++i ){
			mx = max( mx, lis[i] + lds[i] - 1 );
		}
		printf( "%d\n", mx );
	}
}
