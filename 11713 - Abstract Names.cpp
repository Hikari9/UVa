/**
	UVa 11713 - Abstract Names
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.025s C++
	O(n) time
*/
#include<cstdio>
int n;
char a[25],b[25];
bool isVowel(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
bool cmp(){
	for(int i=0;;i++){
		if(a[i]==b[i]){
			if(a[i]=='\0') return true;
		}
		else{
			bool A = isVowel(a[i]), B = isVowel(b[i]);
			if(A!=B) return false;
			else if(!A && a[i]!=b[i]) return false;
		}
	}
}
int main(){
	scanf("%d\n",&n);
	while(n--){
		gets(a);
		gets(b);
		if(cmp()) puts("Yes");
		else puts("No");
	}
}
