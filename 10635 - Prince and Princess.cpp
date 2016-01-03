/**
	UVa 10635 - Prince and Princess
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.062s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int t, tc, n, p, q, i;
set<int> dp;
set<int>::iterator it;
int P[62505], Q[62505], R[62505], len, ans;
int map[62505];
int LIS(){
	dp.clear();
	for( i=0; i<len; ++i ){
		// cout << R[i] << endl;
		it = dp.insert( R[i] ).first;
		if( ++it != dp.end() ) dp.erase(it);
	}
	return dp.size();
}
int main(){
	scanf("%d",&t);
	while(tc<t){
		scanf( "%d %d %d", &n, &p, &q );
		memset( map, -1, sizeof map );
		if( q<p ){
			for( i=0; i<=p; ++i ){
				scanf( "%d", P+i );
				map[ P[i] ] = i;
			}
			for( i=0, len=0; i<=q; ++i ){
				scanf( "%d", Q+i );
				if( map[Q[i]]!=-1 ){
					R[len++] = map[Q[i]];
				}
			}
			printf( "Case %d: %d\n", ++tc, LIS() );
		}
		else{
			for( i=0; i<=p; ++i ){
				scanf( "%d", P+i );
			}
			for( i=0; i<=q; ++i ){
				scanf( "%d", Q+i );
				map[ Q[i] ] = i;
			}
			for( i=0, len=0; i<=p; ++i ){
				if( map[P[i]]!=-1 ){
					R[len++] = map[P[i]];
				}
			}
			printf( "Case %d: %d\n", ++tc, LIS() );
		}
	}
}
