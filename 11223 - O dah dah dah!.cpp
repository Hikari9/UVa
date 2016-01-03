/**
	UVa 11223 - O: dah dah dah!
	by Rico Tiongson
	Submitted: August 16, 2013
	Accepted 0.009s C++
	O(logn) time
*/
// #include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<utility>

using namespace std;
typedef pair<string,char> PAIR;
const char* letterCodes[] = {
	".-", 		"-...", 	"-.-.", 	"-..",
	".", 		"..-.",		"--.",		"....",
	"..",		".---",		"-.-",		".-..",
	//M
	"--",		"-.",		"---",		".--.",
	"--.-",		".-.",		"...",		"-",
	"..-",		"...-",		".--",		"-..-",
	"-.--",		"--.."
};
const char* numberCodes[] = {
	"-----", ".----", "..---", "...--", "....-",
	".....", "-....", "--...", "---..", "----."
};
const PAIR specialCharacterCodes[] = {
	PAIR( ".-.-.-", '.' ),
	PAIR( "--..--", ',' ),
	PAIR( "..--..", '?' ),
	PAIR( ".----.", '\'' ),
	PAIR( "-.-.--", '!' ),
	PAIR( "-..-.", '/' ),
	PAIR( "-.--.", '(' ),
	PAIR( "-.--.-", ')' ),
	PAIR( ".-...", '&' ),
	PAIR( "---...", ':' ),
	PAIR( "-.-.-.", ';' ),
	PAIR( "-...-", '=' ),
	PAIR( ".-.-.", '+' ),
	PAIR( "-....-", '-' ),
	PAIR( "..--.-", '_' ),
	PAIR( ".-..-.", '"' ),
	PAIR( ".--.-.", '@' )
};
map<string,char> morse( specialCharacterCodes, specialCharacterCodes+17 );
int i, j, k, n;
char ln[2005], *p, *p2;
int main(){
	for( i=0; i<10; ++i )
		morse[ numberCodes[i] ] = ('0'+i);
	for( i=0; i<26; ++i )
		morse[ letterCodes[i] ] = ('A'+i);
	scanf( "%d\n", &n );
	for( i=0; i<n; ){
		gets(ln);
		if( i ) putchar( '\n' );
		printf( "Message #%d\n", ++i );
		p = strtok(ln," ");
		while( p!=NULL ){
			if( p-ln>2 && *(p-2)=='\0' ) putchar(' ');
			putchar( morse[p] );
			p = strtok(NULL," ");
		}
		putchar( '\n' );
	}
}
