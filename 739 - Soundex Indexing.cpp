/**
	UVa 1534 - Soundex Indexing
	by Rico Tiongson
	Submitted: August 1, 2013
	Accepted 0.035s C++
	O(n) time
*/
#include<cstdio>
using namespace std;
char s[30], prev;
char soundex[27] = "01230120022455012623010202";
int i, j;
int main(){
	puts( "         NAME                     SOUNDEX CODE" );
	while( gets(s) ){
		char ans[5] = "0000";
		ans[0] = s[0];
		prev = soundex[ s[0]-'A' ];
		for( i=1, j=0; s[i]; ++i ){
			if( prev!=soundex[ s[i]-'A' ] ){
				prev = soundex[ s[i]-'A' ];
				if( prev!='0' ){
					ans[++j] = prev;
					if( j==3 ) break;
				}
			}
		}
		printf("         %-25s%s\n", s, ans);
	}
	puts("                   END OF OUTPUT");
	return 0;
}
