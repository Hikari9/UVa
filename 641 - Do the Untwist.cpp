/**
	UVa 641 - Do the Untwist
	by Rico Tiongson
	Submitted: October 24, 2013
	Accepted 0.022s C++
	O(n) time
*/
#include<iostream>
#include<map>
using namespace std;

int k; string txt;

map<char, int> code;
char text[] = "_abcdefghijklmnopqrstuvwxyz.";

int main(){
	for( int i=0; i<28; ++i ) code[text[i]] = i;
	while( cin >> k >> txt ){
		int N = txt.length();
		int plaincode[N];
		for( int i=0; i<N; ++i ){
			plaincode[(k*i)%N] = (code[ txt[i] ] + i) % 28;
			if( plaincode[(k*i)%N] < 0 ) plaincode[(k*i)%N] += 28; 
		}
		for( int i=0; i<N; ++i ){
			cout << text[plaincode[i]];
		}
		cout << endl;
	}
}
