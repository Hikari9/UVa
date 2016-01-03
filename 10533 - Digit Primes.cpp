/**
	UVa 10533 - Digit Primes
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted 0.385s C++
	O(logn) fetch + O(1.5logn) pre-gen time
*/
//#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> primes,v;
void addprime(int x){
	int lim = sqrt(x)+1;
	for(int i=1;primes[i]<lim;i++){
		if(x%primes[i]==0) return;
	}
	primes.push_back(x);
}
void calc(){
	int x,y;
	for(int i=0;i<primes.size();i++){
		x = primes[i];
		y=0;
		while(x!=0){
			y+=x%10;
			x/=10;
		}
		if(binary_search(primes.begin(),primes.begin()+16,y)) v.push_back(primes[i]);
	}
}
int main(){
	primes.push_back(2);
	primes.push_back(3);
	for(int i=5;i<1000000;i+=4){
		addprime(i);
		addprime(i+=2);
	}
	calc();
	int n,a,b,temp;
	vector<int>::iterator it;
	scanf("%d",&n); //cin >> n;
	while(n--){
		scanf("%d %d",&a,&b); //cin >> a >> b;
		if(b<a){
			temp = b;
			b = a;
			a = temp;
		}
		it = lower_bound(v.begin(),v.end(),a);
		printf("%d\n",upper_bound(it,v.end(),b)-it); //cout << upper_bound(it,v.end(),b)-it << endl;
	}
}
