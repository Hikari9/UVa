/**
	UVa 11362 - Phone List
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.115s C++
	O(nlogn) time
*/
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
size_t i, j;
struct cmp{
	bool operator()( const string& lhs, const string& rhs ){
		for( i=0, j=min(lhs.size(),rhs.size()); i<j; ++i ){
			if( lhs[i]!=rhs[i] ) return lhs[i]<rhs[i];
		}
		return false;
	}
};
set<string,cmp> s;
int t, n;
char buf[20];
bool f;
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d", &n );
		s.clear();
		f = true;
		while( n-- ){
			scanf( "%s", buf );
			if(f){
				if( !s.insert(buf).second )
				f = false;
			}
		}
		if(f) puts("YES");
		else puts("NO");
	}
}
