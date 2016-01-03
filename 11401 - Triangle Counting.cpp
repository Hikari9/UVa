/**
	UVa - Triangle Counting
	by Rico Tiongson
	Submitted: May 12, 2013
	Accepted 0.289s C++
	O(3n) pre-gen + O(1) time
*/
#include<iostream>
#include<vector>
#define mx 1000001
using namespace std;
int main(){
	vector<vector<unsigned long long> > f(mx,vector<unsigned long long>(3));
	unsigned long long count=2;
	for(int i=4;;i++){
		f[i][2] = count;
		if(++i==mx) break;
		f[i][2] = count++;
	}
	f[4][1] = 2;
	for(int i=5;i<mx;i++) f[i][1] = f[i-1][1] + f[i-1][2];
	f[4][0] = 1;
	for(int i=5;i<mx;i++) f[i][0] = f[i-1][0] + f[i-1][1];
	int n;
	while(cin >> n,n>2) cout << f[n][0] << endl;
}
