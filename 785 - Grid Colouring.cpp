/**
	UVa 785 - Gric Colouring
	by Rico Tiongson
	Submitted: May 1, 2013
	Accepted 0.279s C++
	O(n) time
*/
#include<iostream>
#include<cstring>
using namespace std;
char c[105][105],ch;
int n=0;
void Fill(const int& i, const int& j){
	if(i>-1&&j>-1&&i<n&&c[i][j]&&c[i][j]!=ch&&c[i][j]&&c[i][j]!='X'){
		c[i][j]=ch;
		Fill(i-1,j);
		Fill(i+1,j);
		Fill(i,j-1);
		Fill(i,j+1);
	}
}
int main(){
	while(cin.getline(c[n],105)){
		if(c[n][0]=='_'){
			for(int i=0;i<n;i++){
				for(int j=0;c[i][j];j++){
					if(c[i][j]!='X'&&c[i][j]!=' '){
						ch=c[i][j];
						c[i][j]=' ';
						Fill(i,j);
					}
				}
			}
			for(int i=0;i<=n;i++) cout << c[i] << endl;
			n=0;
		}
		else n++;
	}
}

