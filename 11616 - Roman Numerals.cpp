/**
	UVa 11616 - Roman Numerals
	by Rico Tiongson
	Submitted: June 10, 2013
	Accepted 0.038s C++
	O(log10(n)) time
*/
#include<iostream>
#include<cctype>
using namespace std;
string s;
char I[] = " IXCM", V[] = " VLD";
int ans;
int main(){
	while(cin >> s){
		if(isdigit(s[0])){
			for(int i=0;i<s.size();++i){
				if(s[i]>'4'){
					if(s[i]=='9') cout << I[s.size()-i] << I[s.size()-i+1];
					else{
						cout.width( s[i]-'5'+1 );
						cout.fill( I[s.size()-i] );
						cout << left << V[s.size()-i];
					}
				}
				else{
					if(s[i]=='4') cout << I[s.size()-i] << V[s.size()-i];
					else if(s[i]!='0'){
						cout.width( s[i]-'0' );
						cout.fill( I[s.size()-i] );
						cout << I[s.size()-i];
					}
				}
			}
		}
		else{
			switch(s[0]){
				case 'I':
					ans=1;
					break;
				case 'V':
					ans=5;
					break;
				case 'X':
					ans=10;
					break;
				case 'L':
					ans=50;
					break;
				case 'C':
					ans=100;
					break;
				case 'D':
					ans=500;
					break;
				case 'M':
					ans=1000;
					break;
			}
			for(int i=1;i<s.size();++i){
				switch(s[i]){
					case 'I':
						++ans;
						break;
					case 'V':
						if(s[i-1]=='I') ans+=3;
						else ans+=5;
						break;
					case 'X':
						if(s[i-1]=='I') ans+=8;
						else ans+=10;
						break;
					case 'L':
						if(s[i-1]=='X') ans+=30;
						else ans+=50;
						break;
					case 'C':
						if(s[i-1]=='X') ans+=80;
						else ans+=100;
						break;
					case 'D':
						if(s[i-1]=='C') ans+=300;
						else ans+=500;
						break;
					case 'M':
						if(s[i-1]=='C') ans+=800;
						else ans+=1000;
						break;
				}
			}
			cout << ans;
		}
		cout << endl;
	}
}
