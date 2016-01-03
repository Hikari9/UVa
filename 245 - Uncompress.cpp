/**
	UVa 245 - Uncompress
	by Rico Tiongson
	Submitted: July 29, 2013
	Accepted 0.319s C++
	O(nlogn) time
*/
#include<iostream>
#include<vector>
#include<set>
#include<cctype>
#include<algorithm>
using namespace std;
vector<string> v;
set<string> s;
string buf, word;
bool alpha;
int i, x;
int main(){
	while( getline( cin, buf ), buf!="0" ){
		alpha = false;
		word.clear();
		for( i=0; i<buf.size(); ++i ){
			if( isalpha( buf[i] ) ){
				word.clear();
				word.push_back( buf[i] );
				while( ++i < buf.size() ){
					if( isalpha( buf[i] ) ){
						word.push_back( buf[i] );
					}
					else{
						--i;
						break;
					}
				}
				if( s.insert( word ).second ){
					v.push_back( word );
				}
				else{
					v.erase( find( v.begin(), v.end(), word ) );
					v.push_back( word );
				}
				cout << word;
			}
			else if( isdigit( buf[i] ) ){
				x = buf[i]-'0';
				while( ++i < buf.size() ){
					if( isdigit( buf[i] ) ){
						x *= 10;
						x += buf[i]-'0';
					}
					else{
						--i;
						break;
					}
				}
				// cerr << x << "XXXX" << endl;
				word = *(v.end()-x);
				v.erase( v.end()-x );
				v.push_back( word );
				cout << word;
				
				// v.push_back( *(v.end()-x) );
				
			}
			else cout << buf[i];
		}
		cout << endl;
	}
}
