/**
	UVa 271 - Simply Syntax
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.069s C++
	O(2n) time
*/
#include<iostream>
using namespace std;
string s;
bool pz(const char& c){
	return c>='p' && c<='z';
}
bool ncdei(const char& c){
	return c=='N' || c=='C' || c=='D' || c=='E' || c=='I';
}
bool ok(int Index){
	for(int i=0;i<s.length();i++){
		if( pz(s[i]) ) s[i]='1';
		else if( !ncdei(s[i]) ) return false;
	}
	for(int i=s.length()-1;i>-1;i--){
		if(s[i]!='1'){
			if(s[i]=='N'){
				if(i<s.length()-1 && s[i+1]=='1'){
					s.erase(i,1);
				}
				else return false;
			}
			else{
				if(i<s.length()-2 && s[i+1]=='1' && s[i+2]=='1'){
					s.erase(i,2);
				}
				else return false;
			}
		}
	}
	return s=="1";
}
int main(){
	while(cin >> s){
		if(ok(0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
