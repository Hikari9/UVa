/**
	UVa 11584 - Partitioning by Palindromes
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.048s C++
	O(<n^3) time
*/
#include<iostream>
#include<cstring>
#define INF 2147483647
using namespace std;
int n,len,v[1005];
char s[1005];
bool isPalindrome(int x, int y){
	while(x<y){
		if(s[x]!=s[y]) return false;
		x++,y--;
	}
	return true;
}
int main(){
	cin >> n;
	while(n--){
		cin >> s;
		len = strlen(s);
		for(int i=2;i<=len;i++) v[i] = INF;
		v[0] = 0;
		v[1] = 1;
		for(int i=1;i<len;i++){
			for(int j=0;j<=i;j++){
				if(isPalindrome(j,i)) v[i+1]=min(v[j]+1,v[i+1]);
			}
		}
		cout << v[len] << endl;
	}
}
