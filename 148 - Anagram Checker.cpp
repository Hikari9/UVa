/**
	UVa 148 - Anagram checker
	by Rico Tiongson
	Submitted: August 24, 2013
	Accepted 0.192s C++
	O(2^n) time
*/
#include<iostream>
#include<sstream>
#include<cstring>
#include<cctype>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct anagram{
	string word;
	int a[26];
	anagram(): word(){ memset( a, 0, sizeof a ); }
	anagram( const string& s ): word(s){
		memset( a, 0, sizeof a );
		for( int i=0; i<word.length(); ++i ){
			if( isupper( word[i] ) )
				++a[ word[i]-'A' ];
		}
	}
	// all greater
	bool operator >= ( const anagram& a )const{
		for( int i=0; i<26; ++i ){
			if( this->a[i] < a.a[i] ) return false;
		}
		return true;
	}
	anagram& operator -= ( const anagram& a ){
		for( int i=0; i<26; ++i ){
			this->a[i] -= a.a[i];
		}
		return *this;
	}
	anagram& operator += ( const anagram& a ){
		for( int i=0; i<26; ++i ){
			this->a[i] += a.a[i];
		}
		return *this;
	}
};
bool isZero( const anagram& a ){
	for( int i=0; i<26; ++i ){
		if( a.a[i] ) return false;
	}
	return true;
}
vector<anagram> v;
vector<string> ans, words;
string s, buf;
anagram a;
void dfs( int x ){
	if( isZero(a) ){
		// check if same set
		if( ans==words ) return;
		// output ans
		cout << s << " =";
		for( int i=0; i<ans.size(); ++i ){
			cout << ' ' << ans[i];
		}
		cout << endl;
		return;
	}
	if( x==v.size() ) return;
	
	// choose version
	if( a>=v[x] ){
		a -= v[x];
		ans.push_back( v[x].word );
		dfs( x+1 );
		ans.pop_back();
		a += v[x];
	}
	// don't choose version
	dfs( x+1 );
}
int main(){
	while( getline(cin,s), s[0]!='#' )
		v.push_back(s);
	
	while( getline(cin,s), s[0]!='#' ){
		
		// get all words
		istringstream is(s);
		words.clear();
		while( is >> buf ){
			words.push_back(buf);
		}
		sort( words.begin(), words.end() );
		
		a = s;
		ans.clear();
		dfs(0);
	}
}
