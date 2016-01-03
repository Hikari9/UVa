/**
	UVa 803 - Page Selection by Keyword
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int r=0, i, j, n;
char buf[10005], *p;
vector< map<string,int> > v;
map<string,int>::iterator it;
pair<int,int> rel[25];
vector<string> key;
bool cmp( const pair<int,int>& lhs, const pair<int,int>& rhs ){
	return lhs.second==rhs.second ? lhs.first > rhs.first : lhs.second < rhs.second;
}
void make_page(){
	getchar();
	gets( buf );
	for( p=buf; *p; ++p ){
		// transform into uppercase
		if( *p>='a' ) *p-=32;
	}
	p = strtok( buf, " " );
	v.push_back( map<string,int>() );
	while( p!=NULL ){
		v.back().insert( pair<string,int>( p, v.back().size() ) );
		p = strtok( NULL, " " );
	}
}
void make_query(){
	getchar();
	gets( buf );
	for( p=buf; *p; ++p ){
		if( *p>='a' ) *p-=32;
	}
	// cout << buf << endl;
	p = strtok( buf, " " );
	key.clear();
	while( p!=NULL ){
		key.push_back( p );
		p = strtok( NULL, " " );
	}
	// find keywords
	for( i=0; i<v.size(); ++i ){
		rel[i].first = i;
		rel[i].second = 0;
		// get relevance
		for( j=0; j<key.size(); ++j ){
			it = v[i].find( key[j] );
			if( it!=v[i].end() ){
				rel[i].second += (8-j)*(8-it->second);
				// cout << (8-j) << " * " << (9-it->second);
			}
		}
	}
	printf("Q%d:", ++r);
	n = v.size();
	make_heap( rel, rel+n, cmp );
	if( !v.empty() ){
		if( rel[0].second ){
			putchar(' ');
			putchar(' ');
			for( i=0, j=min(n,5); i<j; ++i ){
				if( rel[0].second ){
					printf(" P%d",rel[0].first+1);
					pop_heap( rel, rel+n, cmp );
					--n;
				}
				else break;
			}
		}
	}
	putchar('\n');
}
int main(){
	puts("Query Pages");
	while( true ){
		switch( getchar() ){
			case 'P':
				make_page();
				break;
			case 'Q':
				make_query();
				break;
			case 'E': return 0;
		}
	}
}
