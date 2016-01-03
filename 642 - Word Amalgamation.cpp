/**
	UVa 642 - Word Amalgamation
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 0.012s C++
	O(2nlogn) time
*/
#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct anagram{
	int a[26];
	anagram(){ memset( a, 0, sizeof a ); }
	anagram( const anagram& b ){ memcpy( a, b.a, sizeof a ); }
	anagram( const string& s ){
		memset( a, 0, sizeof a );
		for( int i=0; i<s.length(); ++i )
			++a[ s[i]-'a' ];
	}
	bool operator<( const anagram& b )const{ return lexicographical_compare( a, a+26, b.a, b.a+26 ); }
};
typedef map<anagram,set<string> > Map;
Map m;
string s;
int main(){
	while( cin >> s ){
		m.clear();
		while( s!="XXXXXX" ){
			m[ anagram(s) ].insert(s);
			if( !(cin>>s) ) break;
		}
		while( cin >> s, s!="XXXXXX" ){
			anagram a(s);
			if( m.count(a) ){
				set<string>& v = m[a];
				for( set<string>::iterator it=v.begin(); it!=v.end(); ++it ){
					cout << *it << endl;
				}
			}
			else cout << "NOT A VALID WORD" << endl;
			cout << "******" << endl;
		}
	}
}
