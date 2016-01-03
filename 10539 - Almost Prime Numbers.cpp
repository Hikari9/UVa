/**
	UVa 10539 - Almost Prime Numbers
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted: 0.155s C++
	O(1.5n logn) time
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef unsigned long long lag;
vector<lag> primes,v;
void addprime(const lag& x){
	lag lim = sqrt(x) + 1;
	for(int i=1;primes[i]<lim;i++){
		if(x%primes[i]==0) return;
	}
	primes.push_back(x);
}
int main(){
	primes.push_back(2);
	primes.push_back(3);
	for(lag i=5;i<1000000;i+=4){
		addprime(i);
		addprime(i+=2);
	}
	lag mx(1000000000001);
	for(int i=0;i<primes.size();i++){
		lag j(primes[i]*primes[i]);
		while(j<mx){
			v.push_back(j);
			j*=primes[i];
		}
	}
	sort(v.begin(),v.end());
	int n;
	lag low,hi;
	vector<lag>::iterator it;
	cin >> n;
	while(n--){
		cin >> low >> hi;
		it = upper_bound(v.begin(),v.end(),hi);
		cout << it-lower_bound(v.begin(),it,low) << endl;
	}
}
