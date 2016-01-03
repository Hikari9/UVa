/**
	UVa 760 - DNA Sequencing
	by Rico Tiongson
	Submitted: May 7, 2014
	Accepted 0.019s C++
	Suffix Array LCS
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int t, sa[1005], lcp[1005], n;
char s[1005];

bool cmp( int a, int b ){
	for( int i=0; s[a+i] && s[b+i]; ++i ){
		if( s[a+i] != s[b+i] ) return s[a+i] < s[b+i];
	}
}

set<string> ans;

void getstring( int i, int len ){
	char c = s[i+len];
	s[i+len] = 0;
	ans.insert(s + i);
	s[i+len] = c;
}

int main(){
	// scanf( "%d", &t );
	// while(t--){
	bool start = true;
	while( scanf( "%s", s ) == 1 ){
		n = strlen(s);
		int n2 = n+1;
		s[n++] = '#';
		if( scanf( "%s", s + n ) != 1 ) break;
		
		n += strlen(s+n);
		s[n++] = '$';
		s[n] = 0;
		if(start) start = false;
		else putchar( '\n' );
		// cout << s << endl;
		for( int i=0; i<n; ++i ){
			sa[i] = i;
		}
		sort( sa, sa + n, cmp );
		// lcp[n-1] = 0;
		for( int i=0; i<n; ++i ){
			int check=-1;
			lcp[i] = 0;
			for( int j=i+1; j<n; ++j ){
				if( (sa[j] < n2) != (sa[i] < n2) ){
					check = j;
					break;
				}
			}
			if( check == -1 ){
				continue;
			}
			for( int j=0; ; ++j ){
				if( s[sa[i]+j] != s[sa[check]+j] ){
					lcp[i] = j;
					break;
				}
			}
		}
		// for( int i=0; i<n; ++i ) cout << sa[i] << " " << lcp[i] << " " << s+sa[i] << endl;
		// cout << endl;
		int mx = 0;
		for( int i=0; i<n; ++i ){
			if( mx < lcp[i] ){
				mx = lcp[i];
			}
		}
		if( mx == 0 ){
			puts( "No common sequence." );
			continue;
		}
		ans.clear();
		for( int i=0; i<n; ++i ){
			if( mx == lcp[i] ){
				getstring( sa[i], mx );
			}
		}
		for( set<string>::iterator it = ans.begin(); it != ans.end(); ++it )
			cout << *it << endl;
	}
}
