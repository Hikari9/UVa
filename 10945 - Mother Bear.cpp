/**
	UVa 10945 - Mother Bear
	by Rico Tiongson
	Submitted: May 14, 2013
	Accepted 0.018s C++
	O(n/2) time
*/
#include<iostream>
#include<cctype>
using namespace std;
int main(){
	string s;
	int i,j;
	bool ok;
	while(getline(cin,s),s!="DONE"){
		ok = true;
		i = 0;
		j = s.size()-1;
		while(i<j){
			if(!isalpha(s[i])) i++;
			else if(!isalpha(s[j])) j--;
			else{
				if(tolower(s[i])!=tolower(s[j])){
					ok = false;
					break;
				}
				i++,j--;
			}
		}
		if(ok) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
}
