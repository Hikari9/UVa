/**
	UVa 630 - Anagrams (II)
	by Rico Tiongson
	Submitted: November 3, 2013
	Accepted 0.016s C++
	O(nlogn + k) time
*/
#include<iostream>
#include<cstring>
#include<cctype>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class anagram {
	int a[26];
	public:
		anagram(){ memset( a, 0, sizeof a ); }
		anagram( const anagram& x ){ memcpy( a, x.a, sizeof a ); }
		anagram( const string& s ){
			memset( a, 0, sizeof a );
			for( int i=0; i<s.length(); ++i ){
				if( islower( s[i] ) ){
					a[ s[i] - 'a' ]++;
				}
			}
		}
		
		bool operator < ( const anagram& x ) const {
			return lexicographical_compare( a, a+26, x.a, x.a+26 );
		}
};

int t, n;
string in;

map<anagram, vector<string> > m;


int main(){
	cin >> t;
	while(t--){
		cin >> n;
		m.clear();
		for( int i=0; i<n; ++i ){
			cin >> in;
			m[in].push_back( in );
		}
		while( cin >> in, in != "END" ){
			cout << "Anagrams for: " << in << endl;
			vector<string>& ans = m[in];
			if( ans.empty() ){
				cout << "No anagrams for: " << in << endl;
			}
			else{
				for( int i=0; i<ans.size(); ++i ){
					cout.width(3);
					cout.fill(' ');
					cout << right << i+1 << ") " << ans[i] << endl;
				}
			}
		}
		if( t ) cout << endl;
	}
}
