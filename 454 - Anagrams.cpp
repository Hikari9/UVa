/**
	UVa 454 - Anagrams
	by Rico Tiongson
	Submitted: November 3, 2013
	Accepted 0.029s C++
	O(mnlogmlogn) time
*/
#include<iostream>
#include<cstring>
#include<cctype>
#include<set>
#include<map>
using namespace std;

class anagram {
	int a[256];
	public:
		anagram(){
			memset( a, 0, sizeof a );
		}
		anagram( const anagram& x ){
			memcpy( a, x.a, sizeof a );
		}
		anagram( const string& s ){
			memset( a, 0, sizeof a );
			for( int i=0; i<s.length(); ++i ){
				if( !isspace( s[i] ) )
					a[ s[i] ]++;
			}
		}
		
		bool operator < ( const anagram& x ) const {
			return memcmp( a, x.a, sizeof a ) < 0;
		}
};

int t;
string in;

typedef multiset<string> Set;
map<anagram, Set> phrases;
map<anagram, Set>::iterator it;
Set::iterator it1, it2;

multiset< pair<string, string> > ans;
multiset< pair<string, string> >::iterator it3;

int main(){
	cin >> t;
	cin.ignore();
	cin.ignore();
	while( t-- ){
		phrases.clear();
		while( getline( cin, in ) && !in.empty() ){
			phrases[ anagram(in) ].insert( in );
		}
		ans.clear();
		for( it = phrases.begin(); it != phrases.end(); ++it ){
			for( it1 = it->second.begin(); it1 != it->second.end(); ++it1 ){
				it2 = it1;
				for( ++it2; it2 != it->second.end(); ++it2 ){
					ans.insert( make_pair( *it1, *it2 ) );
				}
			}
		}
		for( it3 = ans.begin(); it3 != ans.end(); ++it3 ){
			cout << it3 -> first << " = " << it3 -> second << endl;
		}
		if( t ) cout << endl;
	}
}
