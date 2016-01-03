/**
	UVa 12467 - Secret Word
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.148s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, len, i, j, ans;
int t[1000005];
char s[1000005];

void buildKMP(){
	t[0] = -1;
	t[1] = 0;
	i=2, j=0;
	while( i <= len ){
		if( s[i-1]==s[j] )
			t[i++] = ++j;
		else if( j>0 )
			j = t[j];
		else
			t[i++] = 0;
	}
}

void KMP(){
	len = strlen(s);
	buildKMP();
	i=0, j=0;
	ans = 0;
	while( i + j < len ){
		if( s[len - i - j - 1] == s[j] ){
			if( ++j == len ){
				ans = len;
				return;
			}
			ans = max( j, ans );
		}
		else{
			i += j - t[j];
			if( j > 0 ) j = t[j];
		}
	}
}

int main(){
	scanf( "%d", &n );
	while(n--){
		scanf( "%s", s );
		KMP();
		for( i=ans-1; i>=0; --i ){
			putchar( s[i] );
		}
		putchar('\n');
	}
}
