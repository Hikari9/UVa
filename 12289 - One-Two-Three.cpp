/**
	UVa 12289 - One-Two-Three
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted 0.012s C++
	O(3) time
*/
#include<iostream>
using namespace std;
int main(){
	int n,wr;
	char c[10],one[]="one";
	cin >> n;
	while(n--){
		cin >> c;
		wr=0;
		if(c[3]=='\0'){
			for(int i=0;i<3;i++){
				if(c[i]!=one[i]) wr++;
			}
			if(wr>1)
				cout << "2" << endl;
			else cout << "1" << endl;
		}
		else cout << "3" << endl;
	}
}
