#include<iostream>
#include<cstdio>
/**
	UVa 10268 - 498-bis
	by Rico Tiongson
	Submitted: August 22, 2013
	Accepted 0.125s C++
	O(n) time
*/
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define mx 1000001
using namespace std;
int i, sz;
long long f[mx], x, powx, fx;
string buf;
char *p;
int main(){
	while( scanf( "%lld\n", &x )==1 ){
		getline( cin, buf );
		p = strtok( const_cast<char*>( buf.c_str() ), " " );
		sz = 0;
		while( p!=NULL ){
			sscanf( p, "%lld", f+sz );
			p = strtok( NULL, " " );
			++sz;
		}
		reverse( f, f+sz );
		fx = 0LL;
		powx = 1LL;
		for( i=1; i<sz; ++i ){
			fx += f[i]*i*powx;
			powx *= x;
		}
		printf( "%lld\n", fx );
	}
}
