/**
	UVa 12100 - Printer Queue
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.012s C++
	O(n) time
*/
#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct cmp{
	bool operator()(const pair<char,int>& lhs, const pair<char,int>& rhs) const{ return lhs.first==rhs.first? lhs.second<rhs.second:lhs.first<rhs.first; }
};
int main(){
	int c,m,n,t;
	char buf[100005],*x;
	map<char,int> Map;
	map<char,int>::iterator it;
	queue<pair<char,int> > q;
	cin >> t;
	while(t--){
		(cin >> n >> m).ignore();
		Map.clear();
		while(!q.empty()) q.pop();
		cin.getline(buf,1000005);
		for(int i=0;i<n;i++){
			q.push(pair<char,int>(buf[2*i],i));
			Map[buf[2*i]]++;
		}
		c = 0;
		it = Map.end();
		it--;
		while(true){
			while(q.front().first!=it->first){
				q.push(q.front());
				q.pop();
			}
			c++;
			if(q.front().second==m) break;
			q.pop();
			if(!--it->second) it--;
		}
		cout << c << endl;
	}
}
