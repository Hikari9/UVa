/**
	UVa 927 - Integer Sequences from Addition of Terms
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.006s C++
	O(logn) time
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define mx 1415
using namespace std;
typedef long long lag;
int I;
lag dd[mx],poly[21];
lag POLYMERIZATION(lag n){
	lag ans = poly[0],expo=n;
	for(int i=1;i<=I;i++){
		ans += poly[i]*expo;
		expo*=n;
	}
	return ans;
}
int main(){
	dd[0] = 0;
	for(int i=1;i<mx;i++)
		dd[i] = dd[i-1] + i;
	int c,d;
	double k;
	cin >> c;
	while(c--){
		cin >> I;
		for(int i=0;i<=I;i++)
			cin >> poly[i];
		cin >> d >> k;
		cout << POLYMERIZATION(lower_bound(dd,dd+mx,k/d)-dd) << endl;
	}
}
