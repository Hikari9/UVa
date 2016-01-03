/**
	UVa 11362 - Phone List
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.136s C++
	O(2nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int t, n, i;
set<string> s;
set<string>::iterator it, it2;
char buf[15];
bool isPrefix( const string& a, const string& b ){
	if( a.size() > b.size() ) return false;
	for( i=0; i<a.size(); ++i ){
		if( a[i] != b[i] ) return false;
	}
	return true;
}
bool check(){
	it2 = s.begin();
	it = it2;
	while( ++it2 != s.end() ){
		if( isPrefix( *it, *it2 ) )
			return false;
		++it;
	}
	return true;
}
int main(){
	scanf("%d", &t);
	while( t-- ){
		s.clear();
		scanf("%d", &n);
		while( n-- ){
			scanf("%s",buf);
			s.insert(buf);
		}
		if( check() ) puts("YES");
		else puts("NO");
	}
}
