/**
	UVa 11730 - Number Transformation
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.012s C++
	O(n) BFS + O(nlogn) prime time
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> N[1001];
bool v[1001];
int s,t,r=0,temp,mx;
int bfs(){
	if(s>t) return -1;
	fill(v,v+t+1,false);
	queue<pair<int,int> > q;
	pair<int,int> p;
	q.push(pair<int,int>(s,0));
	v[s] = true;
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(p.first==t) return p.second;
		if(p.first<t){
			p.second++;
			for(int i=0;i<N[p.first].size();i++){
				temp = N[p.first][i];
				if(!v[temp]){
					v[temp] = true;
					q.push(pair<int,int>(temp,p.second));
				}
			}
		}
	}
	return -1;
}
vector<int> primes;
void addprime(int x){
	int lim = sqrt(x)+1;
	for(int i=1;primes[i]<lim;i++){
		if(x%primes[i]==0) return;
	}
	primes.push_back(x);
}
int main(){
	primes.push_back(2);
	primes.push_back(3);
	for(int i=5;i<334;i+=4){
		addprime(i);
		addprime(i+=2);
	}
	for(int i=0;i<primes.size();i++)
		for(int j=3*primes[i];j<1001;j+=primes[i])
			N[j-primes[i]].push_back(j);
	while(cin >> s >> t,s||t)
		cout << "Case " << ++r << ": " << bfs() << endl;
}
