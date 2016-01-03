/**
	UVa 11222 - Only I Did It!
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.019s C++
	O(3nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int t, n, a, i=0, j, x[10001], ans[3], mx;
set<int> s[3];
set<int>::iterator it;
int main(){
	scanf("%d",&t);
	while( i<t ){
		memset(x,0,sizeof(x));
		for( j=0; j<3; ++j ){
			s[j].clear();
			scanf("%d",&n);
			while( n ){
				scanf("%d",&a);
				if( s[j].insert( a ).second ) ++x[a];
				--n;
			}
		}
		a = 0;
		for( j=0; j<3; ++j ){
			for( it=s[j].begin(); it!=s[j].end(); ){
				if( x[*it]!=1 ) s[j].erase(it++);
				else ++it;
			}
		}
		printf("Case #%d:\n",++i);
		mx = max( s[0].size(), max( s[1].size(), s[2].size() ) );
		for( j=0; j<3; ++j ){
			if( s[j].size()==mx ){
				printf( "%d %d", j+1, s[j].size() );
				for( it=s[j].begin(); it!=s[j].end(); ++it ) printf(" %d",*it);
				putchar('\n');
			}
		}
	}
}
