/**
	UVa 10950 - Bad Code
	by Rico Tiongson
	Submitted: June 12, 2013
	Accepted 0.029s C++
	O(?) time
*/
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string s[26];
char buf[150], *p;
char ans[999];
int n,i,len,sz,r=0,c;
bool found;
void dfs( int x ){
	if(x==len){
		for( i=0; i<sz; ++i ) putchar(ans[i]);
		putchar('\n');
		++c;
		return;
	}
	int xcopy = x;
	for( int j=0; j<26; ++j ){
		if(!s[j].empty()){
			while( buf[x]=='0' ) ++x;
			found = true;
			for( i=0; i<s[j].size(); ++i ){
				if(s[j][i]!=buf[x+i]){
					found = false;
					break;
				}
			}
			if(found){
				ans[sz++] = j+'a';
				dfs( x+s[j].size() );
				if(c==100) return;
				--sz;
			}
			x=xcopy;
		}
	}
}
int main(){
	scanf("%d",&n);
	getchar();
	while(n){
		for( i=0; i<26; ++i ){
			s[i].clear();
		}
		while(n){
			i = getchar()-'a';
			getchar();
			gets(buf);
			p = buf;
			while(*p=='0') ++p;
			s[i] = p;
			--n;
		}
		gets(buf);
		len = strlen(buf);
		c = sz = 0;
		printf("Case #%d\n",++r);
		dfs(0);
		putchar('\n');
		scanf("%d",&n);
		getchar();
	}
}
