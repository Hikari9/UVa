/**
	UVa 10394 - Twin Primes
	by Rico Tiongson
	Submitted: May 5, 2013
	Accepted 2.896s C++
	O(1.5logn) time
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<int,int> Pair;
vector<int> primes;
vector<Pair> pairs;
bool addprime(int x){
	int lim = sqrt(x)+1;
	for(int i=0;primes[i]<lim;i++){
		if(x%primes[i]==0) return false;
	}
	primes.push_back(x);
	return true;
}
int main(){
	primes.push_back(3);
	pairs.push_back(Pair(3,5));
	bool b,c;
	for(int i=5;;i+=6){
		b = addprime(i);
		c = addprime(i+2);
		if(b&&c){
			pairs.push_back(Pair(i,i+2));
			if(pairs.size()==100000) break;
		}
	}
	int n;
	while(cin >> n){
		n--;
		cout << '(' << pairs[n].first << ", " << pairs[n].second << ')' << endl;
	}
}
