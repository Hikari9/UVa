/**
	UVa 146 - Hardwood Species
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.768s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n, total;
char s[35];
map<string,int> m;
map<string,int>::iterator it;
int main(){
	scanf( "%d", &n );
	gets(s); gets(s);
	while(n--){
		m.clear();
		total = 0;
		while( gets(s) && s[0] ){
			++m[s];
			++total;
		}
		for( it = m.begin(); it != m.end(); ++it ){
			cout << it->first;
			printf( " %.4lf\n", (double)(100*it->second) / total );
		}
		if(n) putchar('\n');
	}
}
