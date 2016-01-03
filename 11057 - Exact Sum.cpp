/**
	UVa 11057 - Exact Sum
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.079s C++
	O(0.5logn+2) time
*/
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
bool cmp(const pair<int,int>& a, const pair<int,int>& b){
	return a.first < b.first;
}
int main(){
	set<int> s1,s2;
	set<int>::iterator it;
	int n,midval,midcount,val,x[10005];
	bool ok;
	while(cin >> n){
		s1.clear();
		s2.clear();
		for(int i=0;i<n;i++) cin >> x[i];
		cin >> val;
		midval = val/2;
		midcount = 0;
		for(int i=0;i<n;i++){
			if(x[i]>midval) s2.insert(x[i]);
			else if(x[i]<midval) s1.insert(x[i]);
			else{
				if(++midcount==2){
					cout << "Peter should buy books whose prices are " << midval << " and " << midval << '.' << endl << endl;
					break;
				}
			}
		}
		if(midcount!=2){
			for(it=s2.begin();it!=s2.end();it++){
				if(s1.find(val-*it)!=s1.end()){
					cout << "Peter should buy books whose prices are " << val-*it << " and " << *it << '.' << endl << endl;
					break;
				}
			}
		}
	}
}
