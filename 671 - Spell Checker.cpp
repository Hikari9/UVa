/**
	UVa 671 - Spell Checker
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.136s C++
	O(logn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
using namespace std;
typedef map<string,int>::iterator mii;
struct cmp{
	bool operator()( const mii& lhs, const mii& rhs )const{
		return lhs->second < rhs->second;
	}
};
int t, i;
bool adj;
bool ajusted( const string& a, const string& b ){
	adj = false;
	for( i=0; i<a.size(); ++i ){
		if( a[i] != b[i] ){
			if( adj ) return false;
			adj = true;
		}
	}
	return adj;
}
bool inserted( const string& a, const string& b ){
	adj = false;
	for( i=0; i<a.size(); ++i ){
		if( a[i] != b[i+adj] ){
			if( adj ) return false;
			adj = true;
			--i;
		}
	}
	return true;
}
map<string,int> m[20];
set<mii,cmp> ans;
set<mii,cmp>::iterator it2;
mii it;
string::iterator sit;
char temp, buf[20];

string s;
int main(){
	// cout << inserted( "m", "me" ) << endl;
	scanf("%d", &t);
	while( t ){
		for( i=0; i<20; ++i ) m[i].clear();
		i = 0;
		scanf("%s",buf);
		while( buf[0]!='#' ){
			m[ strlen(buf) ][ buf ] = ++i;
			scanf("%s",buf);
		}
		scanf("%s",buf);
		while( buf[0]!='#' ){
			s = buf;
			if( m[ s.size() ].find( s )!=m[ s.size() ].end() ){
				printf("%s is correct\n",buf);
				scanf("%s",buf);
				continue;
			}
			ans.clear();
			// get deleted
			for( it = m[ s.size()-1 ].begin(); it != m[ s.size()-1 ].end(); ++it ){
				if( inserted( it->first, s ) ) ans.insert( it );
			}
			// get adjusted
			for( it = m[ s.size() ].begin(); it != m[ s.size() ].end(); ++it ){
				if( ajusted( s, it->first ) ) ans.insert( it );
			}
			// get inserted
			for( it = m[ s.size()+1 ].begin(); it != m[ s.size()+1 ].end(); ++it ){
				if( inserted( s, it->first ) ) ans.insert( it );
			}
			printf("%s:",buf);
			for( it2 = ans.begin(); it2 != ans.end(); ++it2 ){
				cout << ' ' << (**it2).first;
			}
			putchar('\n');
			scanf("%s",buf);
		}
		if( --t ) putchar('\n');
	}
}
