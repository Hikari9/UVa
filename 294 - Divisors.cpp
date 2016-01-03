/**
	UVa 294 - Divisors
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.159s C++
	O(nlogn) time
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int mx,mxcount,L,U,d,n,temp;
	cin >> n;
	while(n--){
		cin >> L >> U;
		cout << "Between " << L << " and " << U << ", ";
		mxcount=0;
		if(L==1){
			mx=1;
			mxcount=1;
			L++;
		}
		for(;L<=U;L++){
			temp = 1;
			d = ceil(sqrt(L));
			for(int i=2;i<d;i++){
				if(L%i==0) temp++;
			}
			temp*=2;
			if(d*d==L) temp++;
			if(mxcount<temp){
				mxcount=temp;
				mx=L;
			}
		}
		cout << mx << " has a maximum of " << mxcount << " divisors." << endl;
	}
}
