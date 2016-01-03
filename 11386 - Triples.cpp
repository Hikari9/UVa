/**
	UVa 11386 - Triples
	by Rico Tiongson
	Submitted: May 23, 2013
	Accepted 6.779s C++
	O((log n)*n^2) time
*/
#include<iostream>
#include<map>
using namespace std;
typedef long long lag;
int main(){
	lag n,c,x;
	map<lag,lag> m;
	map<lag,lag>::iterator it,it2,it3;
	while(cin >> n){
		m.clear();
		while(n--){
			cin >> x;
			m[x]++;
		}
		c=0;
		for(it=m.begin();it!=m.end();it++){
			//check same
			it3 = m.find((it->first) << 1);
			if(it3!=m.end()) c += ( (it->second*(it->second-1)) >> 1 )*it3->second;
			it2 = it;
			while(++it2!=m.end()){
				it3 = m.find(it->first + it2->first);
				if(it3!=m.end()){
					c += it->second*it2->second*it3->second;
				}
			}
		}
		cout << c << endl;
	}
}
