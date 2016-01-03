/**
	UVa 11860 - Document Analyzer
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.552s C++
	O(nlogn) assignment + O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<map>
using namespace std;

int t, tc;
char s[155];

vector<int> words;
map<string, int> id;

int used[100005], cnt;

int main(){
	scanf( "%d", &t );
	gets(s);
	while( tc < t ){
		words.clear();
		id.clear();
		while( gets(s) ){
			if( strcmp(s, "END") == 0 ) break;
			int i, j, len = strlen(s);
			for( i=0; i<len; i=j+1 ){
				for( j=i; islower(s[j]); ++j );
				if( i != j ){
					s[j] = '\0';
					words.push_back( id.insert( make_pair(s+i, id.size()) ).first->second );
				}
			}
		}
		memset( used, 0, sizeof used );
		int i=0, j, needed = id.size();
		int st=0, ed=words.size()-1;
		cnt = 0;
		for( j=0; j<words.size(); ++j ){
			if( ++used[words[j]] == 1 ){
				++cnt;
			}
			while( cnt == needed && i <= j ){
				if( j-i < ed-st ){
					st = i;
					ed = j;
				}
				if( --used[words[i++]] == 0 ) --cnt;
			}
		}
		printf( "Document %d: %d %d\n", ++tc, st+1, ed+1 );
	}
}
