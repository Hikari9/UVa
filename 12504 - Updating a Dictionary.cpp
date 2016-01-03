/**
	UVa 12504 - Updating a Dictionary
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.032s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef map<string,string> Map;
Map m[2];
Map::iterator it, it2;
char buf[110], *p, *p2, c;
int n;
bool changes, hasChanged;
void addChange(){
	if( changes ) cout << ',';
	else{
		cout << c;
		hasChanged = changes = true;
	}
}
void makeMap( Map& M ){
	M.clear();
	gets( buf );
	p = strtok( buf, "{:,}" );
	while( p!=NULL ){
		p2 = strtok( NULL, "{:,}" );
		M[p] = p2;
		p = strtok( NULL, "{:,}" );
	}
}
int main(){
	gets( buf );
	n = atoi( buf );
	while( n-- ){
		makeMap( m[0] );
		makeMap( m[1] );
		// track changes
		// additionals
		hasChanged = changes = false;
		c = '+';
		for( it=m[1].begin(); it!=m[1].end(); ){
			it2 = m[0].find( it->first );
			if( it2==m[0].end() ){
				addChange();
				cout << it->first;
				m[1].erase( it++ );
			}
			else ++it;
		}
		if( changes ) cout << endl;
		changes = false;
		c = '-';
		for( it=m[0].begin(); it!=m[0].end(); ++it ){
			it2 = m[1].find( it->first );
			// removed
			if( it2==m[1].end() ){
				addChange();
				cout << it->first;
			}
			else if( it->second==it2->second ){
				m[1].erase( it2 );
			}
			
		}
		// changed value
		if( changes ) cout << endl;
		changes = false;
		c = '*';
		for( it=m[1].begin(); it!=m[1].end(); ++it ){
			addChange();
			cout << it->first;
		}
		if( changes ) cout << endl;
		if( !hasChanged ){
			cout << "No changes" << endl;
		}
		cout << endl;
	}
}
