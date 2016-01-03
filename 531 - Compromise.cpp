/**
	UVa 531 - Compromise
	by Rico Tiongson
	Submitted: May 23, 2013
	Accepted 0.079s C++
	O(?) time dp
*/
#include<iostream>
#include<vector>
using namespace std;
int x[105][105],c;
bool cmp[105][105];
string buf;
vector<string> v1,v2;
int lcs(int i, int j){
	if(i<0 || j<0) return 0;
	if(x[i][j]!=-1) return x[i][j];
	if(v1[i]==v2[j]){
		cmp[i][j] = true;
		return x[i][j] = lcs(i-1,j-1)+1;
	}
	else return x[i][j] = max( lcs(i-1,j), lcs(i,j-1) );
}
void print(int i, int j){
	if(i>=0 && j>=0){
		if(cmp[i][j]){
			if(x[i][j]!=1){
				print(i-1,j-1);
				cout << ' ';
			}
			cout << v1[i];
		}
		else if(x[i-1][j] < x[i][j-1]) print(i,j-1);
		else print(i-1,j);
	}
}
int main(){
	while(!cin.eof()){
		v1.clear();
		while(cin >> buf,buf!="#") v1.push_back(buf);
		v2.clear();
		while(cin >> buf,buf!="#") v2.push_back(buf);
		for(int i=0;i<v1.size();i++){
			for(int j=0;j<v2.size();j++){
				cmp[i][j] = false;
				x[i][j] = -1;
			}
		}
		if(lcs(v1.size()-1,v2.size()-1)){
			print(v1.size()-1,v2.size()-1);
			cout << endl;
		}
	}
}
