/**
	UVa 11824 - A Minimum Land Price
	by Rico Tiongson
	Submitted: June 10, 2013
	Accepted 0.019s C++
	O(nlogn) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long lag;
int T,sz,i;
lag x, l[41], d;
bool flag;
lag POW( lag b, lag e ){
	if(!e) return 1uLL;
	lag e2 = POW(b,e/2);
	if(e%2) return b*e2*e2;
	return e2*e2;
}
int main(){
	cin >> T;
	while(T--){
		flag = false;
		for( sz = 0;; ++sz ){
			cin >> l[sz];
			if(!l[sz]) break;
		}
		make_heap(l,l+sz);
		x=0;
		i=0;
		while( sz ){
			// cout << l[0] << endl;
			d = POW( l[0], ++i );
			if(d>2500000uLL){
				flag = true;
				break;
			}
			x+=d;
			if(x>2500000uLL){
				flag = true;
				break;
			}
			pop_heap(l,l+sz);
			--sz;
		}
		if(flag) cout << "Too expensive" << endl;
		else cout << (x<<1) << endl;
	}
}
