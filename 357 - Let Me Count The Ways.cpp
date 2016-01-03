/**
	UVa 357 - Let Me Count The Ways
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.035s C++
	O(n^2) pre-gen + O(1) time
*/
#include<iostream>
using namespace std;
const int a(30001),b(5);
unsigned long long denom[b]={1,5,10,25,50},ans[a][b];
void CC(){
	for(int i=0;i<a;i++) ans[i][0] = 1LL;
	for(int i=0;i<b;i++) ans[0][i] = 1LL;
	for(int i=1;i<a;i++){
		for(int j=1;j<b;j++){
			if(i>=denom[j]) ans[i][j] = ans[i][j-1] + ans[i-denom[j]][j];
			else ans[i][j] = ans[i][j-1];
		}
	}
}
int main(){
	CC();
	int n;
	while(cin >> n){
		if(ans[n][4]==1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
		else cout << "There are " << ans[n][4] << " ways to produce " << n << " cents change." << endl;
	}
}
