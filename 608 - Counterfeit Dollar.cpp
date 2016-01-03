/**
	UVa 608 - Counterfeit Dollar
	by Rico Tiongson
	Submitted: May 14, 2013
	Accepted 0.088s C++
	O(12n) time
*/
#include<iostream>
using namespace std;
int Left, Right, n;
char x[3][10],y[3][10],z[3][6];
bool isHeavy(char c){
	for(int i=0;i<3;i++){
		Left = Right = 0;
		for(int j=0;x[i][j]!='\0';j++){
			if(x[i][j]==c) Left+=100;
			else Left++;
			if(y[i][j]==c) Right+=100;
			else Right++;
		}
		switch(z[i][0]){
			case 'e':
				if(Left!=Right) return false;
				break;
			case 'u':
				if(Left<=Right) return false;
				break;
			case 'd':
				if(Left>=Right) return false;
		}
	}
	return true;
}
bool isLight(char c){
	for(int i=0;i<3;i++){
		Left = Right = 0;
		for(int j=0;x[i][j]!='\0';j++){
			if(x[i][j]==c) Left-=100;
			else Left++;
			if(y[i][j]==c) Right-=100;
			else Right++;
		}
		switch(z[i][0]){
			case 'e':
				if(Left!=Right) return false;
				break;
			case 'u':
				if(Left<=Right) return false;
				break;
			case 'd':
				if(Left>=Right) return false;
		}
	}
	return true;
}
int main(){
	cin >> n;
	while(n--){
		for(int i=0;i<3;i++) cin >> x[i] >> y[i] >> z[i];
		for(char c='A'; c!='M'; c++){
			if(isHeavy(c)){
				cout.put(c) << " is the counterfeit coin and it is heavy." << endl;
				break;
			}
			else if(isLight(c)){
				cout.put(c) << " is the counterfeit coin and it is light." << endl;
				break;
			}
		}
	}
}
