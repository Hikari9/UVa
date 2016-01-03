/**
	UVa - Known Plaintext Attack
	by Rico Tiongson
	Submitted: October 25, 2013
	Accepted 0.022s C++
	O(n^2logn) time
*/
#include<iostream>
#include<sstream>
#include<set>
#include<vector>
using namespace std;
int t;
string s;
set<string> words;
int main(){
	cin >> t;
	cin.ignore();
	while(t--){
		getline( cin, s );
		istringstream in(s);
		words.clear();
		while( in >> s ) words.insert(s);
		getline( cin, s );
		for( char i='a'; i<='z'; ++i ){
			// cout << s << endl;
			if( words.count(s) )
				cout << i;
			for( int j=0; j<s.length(); ++j ){
				if( ++s[j] > 'z' ){
					s[j] -= 26;
				}
			}
		}
		cout << endl;
	}
}
