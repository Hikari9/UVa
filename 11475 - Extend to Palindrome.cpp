/**
	UVa 11475 - Extend to Palindromes
	by Rico Tiongson
	Submitted: September 11, 2013
	Accepted 2.892s C++
	O(n^2) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[200005];
int i, j, k, len;
inline bool isPalindrome(){
	for( j=i, k=len-1; j<k; ++j, --k ){
		if( c[j]!=c[k] ) return false;
	}
	return true;
}
int main(){
	while( gets(c) ){
		len = strlen(c);
		for( i=0; i<len; ++i ){
			if( isPalindrome() ){
				for( j=i-1, k=len; j>=0; --j, ++k ){
					c[k] = c[j];
				}
				c[k] = '\0';
				break;
			}
		}
		puts(c);
	}
}
