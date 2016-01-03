/**
	UVa 11503 - Virtual Friends
	by Rico Tiongson
	Submitted: August 17, 2013
	Accepted 0.498s C++
	O(logn) time
*/
#include<string>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int t, n, f[100005], a, b, i;
int cnt[100005];
char c1[25], c2[25];
map<string,size_t> m;
int find( int x ){ return f[x]==-1 ? x : f[x]=find(f[x]); }
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d", &n );
		m.clear();
		memset( f, -1, sizeof f );
		for( i=0; i<100005; ++i ) cnt[i] = 1;
		while( n-- ){
			scanf( "%s %s", c1, c2 );
			a = m.insert( make_pair(c1,m.size()) ).first->second;
			b = m.insert( make_pair(c2,m.size()) ).first->second;
			a = find(a);
			b = find(b);
			if( a!=b ){
				f[a] = b;
				cnt[b] += cnt[a];
			}
			printf( "%d\n", cnt[b] );
		}
	}
}
