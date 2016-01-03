/**
	UVa 12503 - Robot Instructions
	by Rico Tiongson
	Submitted:  May 13, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int main(){
	int t,n,p,x;
	char dir[105],in[15];
	cin >> t;
	while(t--){
		cin >> n;
		p=0;
		for(int i=1;i<=n;i++){
			cin >> in;
			switch(in[0]){
				case 'L':
					dir[i] = 'L';
					p--;
					break;
				case 'R':
					dir[i] = 'R';
					p++;
					break;
				case 'S':
					cin >> in >> x;
					if((dir[i]=dir[x])=='L') p--;
					else p++;
			}
		}
		cout << p << endl;
	}
}
