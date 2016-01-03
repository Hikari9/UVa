/**
	UVa 892 - Finding words
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
#include<cctype>
using namespace std;
bool isWord(const char& c){
	return isalpha(c)||c==' ';
}
int main(){
	string s,strip;
	int i,j;
	while(getline(cin,s),s!="#"){
		if(!strip.empty()){
			for(int j=0;j<strip.size();j++){
				if(isWord(strip[j])) cout.put(strip[j]);
			}
			strip.clear();
			for(i=0;i<s.size();i++){
				if(isalpha(s[i])) cout.put(s[i]);
				else if(s[i]==' ') break;
			}
			cout << endl;
		}
		else i=0;
		if(!s.empty() && s[s.size()-1]=='-'){
			for(j=s.size()-1;j>-1;j--){
				if(s[j]==' ') break;
			}
			strip = s.substr(++j);
		}
		else j=s.size();
		while(i<j){
			if(isWord(s[i])) cout.put(s[i]);
			i++;
		}
		cout << endl;
	}
	if(!strip.empty()){
		for(int j=0;j<strip.size();j++){
			if(isWord(strip[j])) cout.put(strip[j]);
		}
		cout << endl;
	}
}
