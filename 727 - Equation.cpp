/**
	UVa 727 - Equation
	by Rico Tiongson
	Submitted: September 13, 2013
	Accepted 0.272s C++
	O(?) time
*/
#include<iostream>
#include<vector>
using namespace std;

string postfix( const string& s ){
	vector<string> v;
	int i, j, st;
	// parenthesis
	for( i=0; i<s.length(); ++i ){
		if( s[i]=='(' ){
			for( j=i+1, st=1; j<s.length(); ++j ){
				if( s[j]=='(' ) ++st;
				else if( s[j]==')' ){
					if( --st==0 ) break;
				}
			}
			v.push_back( postfix( s.substr( i+1, j-i-1 ) ) );
			// find partner
			i = j;
		}
		else{
			v.push_back( s.substr( i, 1 ) );
		}
	}
	// multiplication merge
	for( i=1; i<v.size()-1; ++i ){
		if( v[i]=="*" || v[i]=="/" ){
			v[i-1].append(v[i+1]).append(v[i]);
			v.erase( v.begin()+i, v.begin()+i+2 );
			--i;
		}
	}
	// addition merge
	for( i=1; i<v.size()-1; ++i ){
		if( v[i]=="+" || v[i]=="-" ){
			v[i-1].append(v[i+1]).append(v[i]);
			v.erase( v.begin()+i, v.begin()+i+2 );
			--i;
		}
	}
	// one string should remain
	return v.front();
}

char c[55];
int i, t, sz;

int main(){
	cin >> t;
	cin.ignore().ignore();
	while(t){
		for( i=0; cin.get(c[i]) && c[i]!='\n'; ++i )
			cin.get();
		sz = i;
		c[sz] = '\0';
		cout << postfix(c) << endl;
		if(--t) cout << endl;
	}
}
