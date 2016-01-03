/**
	UVa 484 - Department of Redundancy Department
	by Rico Tiongson
	Submitted: May 5, 2013
	Accepted: 0.035s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
	int x;
	map<int,int> m;
	vector<map<int,int>::iterator> index;
	pair<map<int,int>::iterator,bool> it;
	while(cin >> x){
		it = m.insert(pair<int,int>(x,1));
		if(it.second) //inserted
			index.push_back(it.first);
		else
			it.first->second++;
	}
	for(int i=0;i<index.size();i++)
		cout << index[i]->first << ' ' << index[i]->second << endl;
}
