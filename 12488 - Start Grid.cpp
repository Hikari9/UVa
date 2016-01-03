/**
	UVa 12488 - Start Grid
	by Rico Tiongson
	Submitted: May 26, 2013
	Accepted 0.015s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int x[2][25],n,c,y;
int main(){
	while(cin >> n){
		for(int i=1;i<=n;i++){
			cin >> y;
			x[0][y] = i;
		}
		for(int i=1;i<=n;i++){
			cin >> x[1][i];
		}
		c=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[0][ x[1][i] ] > x[0][ x[1][j] ]) c++;
			}
		}
		cout << c << endl;
	}
}
