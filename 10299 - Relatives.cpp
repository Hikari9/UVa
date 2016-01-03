/**
	UVa 10299 - Relatives
	by Rico Tiongson
	Submitted: June 4, 2013
	Accepted 0.389s C++
	O(sqrt(n)) time
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#define mx 31635
using namespace std;
vector<int> pr;
int f[3505],n;
int phi(int x){
	if(x==1) return 0;
	int ans(x), id(0), pf(f[0]);
	while(x!=1 && pf*pf<=x){
		if(!(x%pf)){
			do{
				x/=pf;
			} while(!(x%pf));
			ans-=ans/pf;
		}
		pf = f[++id];
	}
	if(x!=1) ans-=ans/x;
	return ans;
}
void addprime( int x ){
	int lim = sqrt(x) + 1;
	for(int j=1;pr[j]<lim;++j){
		if(x%pr[j]==0) return;
	}
	pr.push_back(x);
}
int main(){
	pr.push_back(2);
	pr.push_back(3);
	for(int i=5;i<mx;i+=4){
		addprime(i);
		addprime(i+=2);
	}
	int id=-1;
	memset(f,0,sizeof(f));
	for(int i=0;i<pr.size();++i){
		f[++id] = pr[i];
	}
	while(cin >> n,n){
		cout << phi(n) << endl;
	}
}
