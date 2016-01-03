/**
	UVa 11348 - Exhibition
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.032s C++
	O(nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
int k, n, m, a, i=0, j, x[10001], ans[51];
set<int> s[51];
set<int>::iterator it;
int main(){
	scanf("%d",&k);
	while( i<k ){
		memset(x,0,sizeof(x));
		scanf("%d",&n);
		for( j=0; j<n; ++j ){
			s[j].clear();
			scanf("%d",&m);
			while( m ){
				scanf("%d",&a);
				if(s[j].insert( a ).second) ++x[a];
				--m;
			}
		}
		a = 0;
		for( j=0; j<n; ++j ){
			ans[j] = 0;
			for( it=s[j].begin(); it!=s[j].end(); ++it ){
				if( x[*it]==1 ) ++ans[j];
			}
			a += ans[j];
		}
		printf( "Case %d:", ++i );
		for( j=0; j<n; ++j ){
			printf(" %.6lf", double(100.*ans[j])/a);
			putchar('%');
		}
		putchar('\n');
	}
}
