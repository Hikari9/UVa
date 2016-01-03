/**
	UVa 599 - The Forrest for Trees
	by Rico Tiongson
	Submitted: June 13, 2013
	Accepted 0.128s ANSI C
	O(logn) time
*/
#include<stdio.h>
#include<string.h>
int n, a, b, i, f[26], f2[26], trees, acorns;
char c;
int find( int x ){
	if(f[x]==x) return x;
	f[x] = find(f[x]);
	return f[x];
}
int main(){
	scanf("%d",&n);
	getchar();
	while( n ){
		for( i=0; i<26; ++i ) f[i] = i;
		while(getchar()!='*'){
			a = getchar()-'A';
			getchar();
			b = getchar()-'A';
			getchar();
			getchar();
			f[ find(a) ] = find(b);
		}
		while( getchar()!='\n' );
		acorns = trees = 0;
		if( (c=getchar())!='\n' ){
			memset( f2, 0, sizeof(f2) );
			++f2[ find(c-'A') ];
			while( getchar()!='\n' ){
				++f2[ find(getchar()-'A') ];
			}
			for( i=0; i<26; ++i ){
				switch( f2[i] ){
					case 0: break;
					case 1: ++acorns; break;
					default: ++trees; break;
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
		--n;
	}
}
