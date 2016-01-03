/**
	UVa 11679 - Sub-prime
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int main(){
	int b,n,r[21],d,c,v;
	bool ok;
	while(cin >> b >> n, b||n){
		for(int i=1;i<=b;i++) cin >> r[i];
		for(int i=0;i<n;i++){
			cin >> d >> c >> v;
			r[d]-=v;
			r[c]+=v;
		}
		ok = true;
		for(int i=1;i<=b;i++){
			if(r[i]<0){
				ok = false;
				break;
			}
		}
		cout.put(ok?'S':'N') << endl;
	}
}
