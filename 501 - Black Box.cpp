/**
	UVa 501 - by Rico Tiongson
	Submitted: August 18, 2013
	Accepted 0.485s C++
	O(nlogn) time
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t, m, n, i, j, k, cmd;
int a[30005];
vector<int> v;
int main(){
	scanf( "%d", &t );
	while( t ){
		scanf( "%d %d", &m, &n );
		v.clear();
		for( i=0; i<m; ++i ) scanf( "%d", a+i );
		for( i=0, j=0; j<n; ++j ){
			scanf( "%d", &cmd );
			while( i<cmd ){
				v.insert( lower_bound(v.begin(),v.end(),a[i]), a[i] );
				++i;
			}
			printf( "%d\n", v[j] );
		}
		if(--t) putchar('\n');
	}
}
