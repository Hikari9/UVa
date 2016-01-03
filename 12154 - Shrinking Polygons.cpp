/**
	UVa 12154 - Shrinking Polygons
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.045s C++
	O(nsqrtn) time
*/
#include<cstdio>
#include<cstring>
#include<hash_set>
using namespace std;
using namespace __gnu_cxx;
hash_set<int> hs;
int n, i, I, j, k, s[10005], sum, ans;
int pf[10005], sz;
int main(){
	while( scanf("%d",&n)==1 && n ){
		hs.clear();
		for( i=1; i<=n; ++i ){
			scanf( "%d", s+i );
			s[i] += s[i-1];
			hs.insert( s[i] );
		}
		sum = s[n];
		ans = -1;
		sz = 0;
		for( i=1; i*i < sum; ++i ){
			if( sum%i==0 ){
				for( j=0; s[j]<i; ++j ){
					for( k = s[j]+i; k<=sum; k+=i ){
						if( hs.count(k)==0 ) goto outer;
					}
					ans = sum/i;
					if( ans < 3 ) ans = -1; // not polygon
					else ans = n-ans;
					goto done;
					outer:;
				}
				pf[sz++] = i;
			}
		}
		if( i*i==sum ) pf[sz++] = i;
		for( I=sz-1; I>=0; --I ){
			i = sum/pf[I];
			if( sum%i==0 ){
				for( j=0; s[j]<i; ++j ){
					for( k = s[j]+i; k<=sum; k+=i ){
						if( hs.count(k)==0 ) goto outer2;
					}
					ans = sum/i;
					if( ans < 3 ) ans = -1; // not polygon
					else ans = n-ans;
					goto done;
					outer2:;
				}
			}
		}
		done:
		printf( "%d\n", ans );
	}
}
