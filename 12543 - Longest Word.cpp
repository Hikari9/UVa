/**
	UVa 12543 - Longest Word
	by Rico Tiongson
	Submitted: November 3, 2013
	Accepted 0.016s C++
	O(n) time
*/
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

string in, longest;

bool parseWords(){
	for( int i=0, j; i<in.length(); ++i ){
		if( isalpha( in[i] ) || in[i] == '-' ){
			for( j=i+1; j<in.length(); ++j ){
				if( isalpha( in[j] ) || in[j] == '-' );
				else break;
			}
			string s = in.substr( i, j-i );
			transform( s.begin(), s.end(), s.begin(), ::tolower );
			if( s == "e-n-d" ) return false;

			if( s.length() > longest.length() )
				longest = s;
			i = j;
		}
	}
	return true;
}

int main(){
	while( cin >> in && parseWords() );
	cout << longest << endl;
}
