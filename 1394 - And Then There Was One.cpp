/**
	UVa 1394 - And Then There Was One
	by Rico Tiongson
	Submitted: May 23, 2013
	Accepted 0.895s C++
	O(<n^2) time
*/
#include<iostream>
#include<vector>
using namespace std;
int n,k,m;
vector<int> v;
void print(){
	for(int i=0;i<v.size();i++) cout << v[i]+1 << ' ';
	cout << endl;
}
int main(){
	while(cin >> n >> k >> m,n||k||m){
		v.clear();
		for(int i=0;i<n;i++) v.push_back(i);
		k--;
		v.erase(v.begin()+(--m));
		while( v.size()>1 ){
			m = v.erase( v.begin()+((m+k)%v.size()) )-v.begin();
		}
		cout << v.front()+1 << endl;
	}
}
