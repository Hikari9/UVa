/**
	UVa 10131 - Is Bigger Smarter?
	by Rico Tiongson
	Submitted: May 9, 2013
	Accepted 0.012s C++
	O(log n!) sort + O(n^2) time
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INF -1
using namespace std;
struct node{
	int w,iq,id;
	int path;
	node* prev;
	node(int _w, int _iq, int _id):
		w(_w),iq(_iq),id(_id),path(INF){}
	bool operator<(const node& rhs)const{ //sort decreasing order of weight
		return (w==rhs.w) ? (iq<rhs.iq) : (w>rhs.w);
	}
	bool operator()(node& rhs){ //connect
		if( w>rhs.w && iq<rhs.iq && path+1>rhs.path ){
			rhs.path = path+1;
			rhs.prev = this;
		}
	}
};
void out(node* p){
	cout << p->id << endl;
	if(p->path==1) return;
	out(p->prev);
}
int main(){
	int a,b,c(0);
	vector<node> v;
	while(cin >> a >> b)
		v.push_back(node(a,b,++c));
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(v[i].path==INF) v[i].path=1; //1 offset
		for(int j=i+1;j<v.size();j++) v[i]( v[j] ); //connect operator
	}
	node *p = &v[0];
	for(int i=v.size()-1;i>0;i--){
		if(v[i].path > p->path) p = &v[i];
	}
	cout << p->path << endl;
	out(p);
}
