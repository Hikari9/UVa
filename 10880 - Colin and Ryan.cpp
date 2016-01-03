/**
	UVa 10880 - Colin and Ryan
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.059s C++
	O(sqrtn log(sqrt(n))) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
int i, j, c, r, n, lim;
set<int> ans;
set<int>::iterator it;
int main(){
	scanf("%d",&n);
	for( i=1; i<=n; ++i ){
		scanf("%d %d", &c, &r);
		printf("Case #%d:",i);
		if( c==r ){
			puts(" 0");
			continue;
		}
		c-=r;
		lim = sqrt(c)+1;
		ans.clear();
		for( j=1; j<lim; ++j ){
			if( c%j==0 ){
				if( j>r )
				ans.insert(j);
				if( c/j>r )
				ans.insert( c/j );
			}
		}
		for( it=ans.begin(); it!=ans.end(); ++it ){
			printf(" %d", *it);
		}
		putchar('\n');
	}
}
