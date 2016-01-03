/**
	UVa 444 - Encoder and Decoder
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
#include<sstream>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
	string s,ans;
	int x;
	while(getline(cin,s)){
		ans.clear();
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size();){
			if(isdigit(s[i])){
				if(s[i]=='1'){
					istringstream(s.substr(i,3)) >> x;
					i+=3;
				}
				else{
					istringstream(s.substr(i,2)) >> x;
					i+=2;
				}
				ans.push_back(char(x));
			}
			else{
				string rev;
				x = s[i++];
				while(x){
					rev.push_back(x%10+'0');
					x/=10;
				}
				ans.append(rev);
			}
		}
		cout << ans << endl;
	}
}
