/**
	UVa 257 - Palinwords
	by Rico Tiongson
	Submitted: October 26, 2013
	Accepted 0.092s C++
	O(2n) time
*/
#include<iostream>
using namespace std;
string s, word, sub;
bool isPalindrome( int i, int j ){
	while( i < j ){
		if( s[i++] != s[j--] ) return false;
	}
	return true;
}
bool embedded( const string& a, const string& b ){
	return b.find(a) != string::npos;
}
int main(){
	end:
	while( cin >> s ){
		word.clear();
		for( int i=s.length()-3; i>=0; --i ){
			if( isPalindrome(i, i+2) ){
				sub = s.substr(i, 3);
				if( word.empty() ){
					word = sub;
				}
				else if( sub != word ){
					cout << s << endl;
					goto end;
				}
			}
		}
		for( int i=s.length()-4; i>=0; --i ){
			if( isPalindrome(i, i+3) ){
				sub = s.substr(i, 4);
				if( word.empty() ){
					word = sub;
				}
				else if( sub != word ){
					if( !embedded(word, sub) ){
						cout << s << endl;
						goto end;
					}
				}
			}
		}
	}
}
