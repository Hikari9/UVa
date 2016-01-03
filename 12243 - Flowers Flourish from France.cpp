/**
	UVa 12243 - Flowers Flourish from France
	by Rico Tiongson
	Submitted: September 11, 2013
	Accepted 0.019s C++
	O(?) time
*/
#include<cstdio>
#include<cstring>
#include<cctype>
char c[1000001], *p, x;
int main(){
	while( gets(c) ){
		if( strcmp(c,"*")==0 ) return 0;
		p = strtok(c," ");
		x = tolower(p[0]);
		p = strtok(NULL," ");
		while( p!=NULL ){
			if( tolower(p[0])!=x ) break;
			p = strtok(NULL," ");
		}
		puts( p==NULL ? "Y" : "N" );
	}
}
