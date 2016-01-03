/**
	UVa 11661 - Burger Time?
	by Rico Tiongson
	Submitted: May 26, 2013
	Accepted 0.322s C++
	O(n) time
*/
#include<iostream>
#define INF 2147483647
using namespace std;
string s;
int n,mn,curD,curR;
int main(){
	while(cin >> n,n){
		cin >> s;
		if(s.find('Z')!=string::npos) cout << "0" << endl;
		else{
			curD = curR = mn = INF;
			for(int i=0;i<s.size();i++){
				if(s[i]=='R'){
					curR = i;
					if(curD!=INF){
						mn = min(curR-curD,mn);
						curD = INF; //use
					}
				}
				else if(s[i]=='D'){
					curD = i;
					if(curR!=INF){
						mn = min(curD-curR,mn);
						curR = INF; //use
					}
				}
			}
			cout << mn << endl;
		}
	}
}
