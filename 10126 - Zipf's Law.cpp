/**
	UVa 10126 - Zipf's Law
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.095s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
#include<cctype>
#include<algorithm>
using namespace std;
map<string, int> m;
map<string, int>::iterator it;
string buf, word;
int n, i;
bool found, f=false;
int main(){
	while( cin >> n ){
		if( f ) cout << endl;
		f = true;
		m.clear();
		while( cin >> buf ){
			transform( buf.begin(), buf.end(), buf.begin(), ::tolower );
			if( buf=="endoftext" ) break;
			for( i=0; i<buf.size(); ++i ){
				if( islower( buf[i] ) ){
					word.clear();
					do{
						word.push_back( buf[i] );
						++i;
					} while( i<buf.length() && islower( buf[i] ) );
					++m[word];
				}
			}
		}
		found = false;
		for( it=m.begin(); it!=m.end(); ++it ){
			if( it->second == n ){
				cout << it->first << endl;
				found = true;
			}
		}
		if( !found ) cout << "There is no such word." << endl;
	}
}
