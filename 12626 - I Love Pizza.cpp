/**
	UVa 12626 - I <3 Pizza
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.022s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int main(){
	int n,m[26];
	char buf[100005];
	cin >> n;
	while(n--){
		for(int i=0;i<26;i++) m[i] = 0;
		cin >> buf;
		for(int i=0;buf[i]!='\0';i++) m[buf[i]-'A']++;
		cout << min( min( min( m[12], m[0]/3 ), min( m[17]/2, m[6] ) ), min(m[8],m[19]) ) << endl;
	}
}
