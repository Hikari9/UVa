/**
	UVa 12207 - That is Your Queue
	by Rico Tiongson
	Submitted: May 16, 2013
	Accepted 0.025s C++
	O(n) time
*/
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
typedef long long lag;
int main(){
	lag p,c,r=0,x;
	char cmd;
	list<lag>::iterator it;
	while(cin >> p >> c,p){
		list<lag> q;
		cout << "Case " << ++r << ':' << endl;
		p = min(p,c);
		for(int i=1;i<=p;i++) q.push_back(i);
		for(int i=0;i<c;i++){
			cin >> cmd;
			if(cmd=='N'){
				cout << q.front() << endl;
				q.push_back(q.front());
				q.pop_front();
			}
			else{
				cin >> x;
				it = find(q.begin(),q.end(),x);
				if(it!=q.end()) q.erase(it);
				q.push_front(x);
			}
		}
	}
}
