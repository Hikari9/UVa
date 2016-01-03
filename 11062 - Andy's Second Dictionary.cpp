/**
	UVa 11062 - Andy's Second Dictionary
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<sstream>
#include<cctype>
#include<vector>
#include<set>
using namespace std;
int main(){
	set<string> Set;
	vector<char> sbuf;
	char buf[1000005];
	cin.read(buf,1000005);
	sbuf.push_back(tolower(buf[0]));
	for(int i=1;i<cin.gcount();i++){
		if(buf[i]=='\n' && sbuf.back()=='-') sbuf.pop_back();
		else if(isalpha(buf[i])){
			sbuf.push_back(tolower(buf[i]));
		}
		else if(buf[i]=='\n') sbuf.push_back('\n');
		else if(buf[i]!='-') sbuf.push_back(' ');
		else sbuf.push_back('-');
	}
	if(sbuf.back()=='-') sbuf.pop_back();
	istringstream str(string(sbuf.begin(),sbuf.end()));
	while(str >> buf) Set.insert(buf);
	for(set<string>::iterator it = Set.begin();it!=Set.end();it++){
		cout << *it << endl;
	}
}
