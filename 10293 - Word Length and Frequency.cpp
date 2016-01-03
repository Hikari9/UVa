/**
	UVa 10293 - Word Length and Frequency
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int i, sz;
string s, all;
char *p;
const char* delim = " ?!,.";
map<int,int> m;
map<int,int>::iterator it;
int main(){
	while( getline(cin,s) ){
		all.clear();
		m.clear();
		while( s!="#" ){
			all.append(s).append("\n");
			if( !getline(cin,s) ) return 0;
		}
		for( p=strtok( static_cast<char*>((char*)all.c_str()), delim ); p!=NULL; p=strtok(NULL,delim) ){
			// parse
			sz = 0;
			// s.clear();
			for( i=0; p[i]; ++i ){
				if( p[i]=='\n' ){
					if( sz ){
						++m[sz];
						sz = 0;
						// cout << s << endl;
						// s.clear();
					}
				}
				else if( p[i]=='-' && p[i+1]=='\n' ){
					++i;
				}
				else if( p[i]!='\'' && p[i]!='-' ){
					++sz;
					// s.push_back(p[i]);
				}
			}
			if( sz ){
				++m[sz];
				// cout << s << endl;
				// s.clear();
			}
		}
		for( it=m.begin(); it!=m.end(); ++it ){
			cout << it->first << " " << it->second << endl;
		}
		cout << endl;
	}
}
