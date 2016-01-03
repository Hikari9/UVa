/**
	UVa 10515 - Powers Et Al.
	by Rico Tiongson
	Submitted: October 24, 2013
	Accepted 0.069s C++
	O(n) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char a[105], b[105];
char two[] = "2486";
char three[] = "3971";
char seven[] = "7931";
char eight[] = "8426";

int main(){
	while( scanf( "%s %s", a, b ) == 2 && ( strcmp(a, "0") || strcmp(b, "0") ) ){
		if(strcmp(b,"0") == 0 ){
			puts("1");
			continue;
		}
		int len = strlen(a), x;
		int lastChar = a[len-1] - '0';
		switch(lastChar){
			case 0:
				puts("0");
				break;
			case 1:
				puts("1");
				break;
			case 2:
				// divide by four
				len = strlen(b);
				if( len == 1 ) x = b[0] - '0';
				else x = atoi(b + len - 2);
				x = (x-1) & 3;
				printf( "%c\n", two[x] );
				break;
			case 3:
				len = strlen(b);
				if( len == 1 ) x = b[0] - '0';
				else x = atoi(b + len - 2);
				x = (x-1) & 3;
				printf( "%c\n", three[x] );
				break;
			case 4:
				len = strlen(b);
				x = b[len-1] - '0';
				if( x & 1 ) puts("4");
				else puts("6");
				break;
			case 5:
				puts("5");
				break;
			case 6:
				puts("6");
				break;
			case 7:
				len = strlen(b);
				if( len == 1 ) x = b[0] - '0';
				else x = atoi(b + len - 2);
				x = (x-1) & 3;
				printf( "%c\n", seven[x] );
				break;
			case 8:
				len = strlen(b);
				if( len == 1 ) x = b[0] - '0';
				else x = atoi(b + len - 2);
				x = (x-1) & 3;
				printf( "%c\n", eight[x] );
				break;
			case 9:
				len = strlen(b);
				x = b[len-1] - '0';
				if( x & 1 ) puts("9");
				else puts("1");
		}
	}
}
