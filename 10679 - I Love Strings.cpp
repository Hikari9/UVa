/**
	UVa 10679 - I Love Strings!
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 2.742s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<vector>

#define MX 100005
using namespace std;

int t[MX];

void buildKMP( const string& f ){
	t[0] = -1;
	t[1] = 0;
	int i=2, j=0;
	while( i <= f.length() ){
		if( f[i-1]==f[j] )
			t[i++] = ++j;
		else if( j>0 )
			j = t[j];
		else
			t[i++] = 0;
	}
}

// returns index of first match
// use vector to collect all matches

int KMP( const string& s, const string& f ){
	// vector<int> ans;
	int i=0, j=0;
	buildKMP(f);
	while( i+j < s.length() ){
		if( s[i+j]==f[j] ){
			if( ++j == f.length() ){
				return i;
				// ans.push_back(i);
				// i += j-t[j];
				// if( j>0 ) j = t[j];
			}
		}
		else{
			i += j-t[j];
			if( j>0 ) j = t[j];
		}
	}
	return -1;
	// return ans;
}

int k, q;
char str[MX];
string Str;

int main(){
	scanf( "%d", &k );
	while(k--){
		scanf( "%s", str );
		Str = str;
		scanf( "%d", &q );
		while(q--){
			scanf( "%s", str );
			if( KMP(Str, str) == -1 ) puts("n");
			else puts("y");
		}
	}
}
