/**
	UVa 11233 - Deli Deli
	by Rico Tiongson
	Submitted: June 16, 2013
	Accepted 0.012s C++
	O(nlogn+3) time
*/
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
int l, n;
char buf[2][25];
map<string,string> m;
map<string,string>::iterator it;
bool vowel( char c ){
	switch(c){
		case 'a': case 'e': case 'i': case 'o': case 'u': return true;
	}
	return false;
}
bool es(){
	if(!l) return false;
	switch( buf[0][l-1] ){
		case 'h':
			if( l==1 ) return false;
			if( buf[0][l-2]!='c' && buf[0][l-2]!='s' ) return false;
		case 'o':
		case 's':
		case 'x':
			return true;
	}
	return false;
}


int main(){
	scanf("%d %d",&l,&n);
	getchar();
	while( l ){
		scanf("%s %s",buf[0],buf[1]);
		m[buf[0]] = buf[1];
		--l;
	}
	getchar();
	while( n ){
		gets(buf[0]);
		it = m.find(buf[0]);
		if( it==m.end() ){
			l = strlen(buf[0]);
			if( l>1 && buf[0][l-1]=='y' && !vowel(buf[0][l-2]) ){
				buf[0][l-1] = 'i';
				printf("%s",buf[0]);
				puts("es");
			}
			else if( es() ){
				printf("%s",buf[0]);
				puts("es");
			}
			else{
				printf("%s",buf[0]);
				putchar('s');
				putchar('\n');
			}
		}
		else puts(it->second.c_str());
		--n;
	}
}
