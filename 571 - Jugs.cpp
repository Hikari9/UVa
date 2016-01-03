/**
	UVa 571 - Jugs
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.055s C++
	O(ca*cb) time
*/
#include<iostream>
#include<queue>
#include<map>
#include<cstdlib>
using namespace std;
typedef pair<int,int> state;
struct node{
	node* prev;
	int dir; //+A-B 1:fill 2:empty 3:pour
	bool v;
	node(){}
	void reset(){
		v = false;
	}
} v[1005][1005];
int ca,cb,a,b,x,da,db,n;
node* bfs(){
	if(!n) return &v[0][0];
	//else if(n==ca) return v[ca][0].prev = &v[0][0];
	else if(n==cb){
		v[0][cb].dir = -1;
		v[0][cb].prev = &v[0][0];
		return &v[0][cb];
	}
	for(int i=0;i<=ca;i++){
		for(int j=0;j<=cb;j++) v[i][j].reset();
	}
	queue<state> q;
	q.push(state(0,0));
	v[0][0].v = true;
	while(!q.empty()){
		a = q.front().first;
		b = q.front().second;
		x = a+b;
		q.pop();
		//fill A
		if(!v[ca][b].v){
			v[ca][b].v = true;
			v[ca][b].dir = 1;
			v[ca][b].prev = &v[a][b];
			// if(b==n) return &v[ca][b];
			q.push( state(ca,b) );
		}
		//empty A
		if(!v[0][b].v){
			v[0][b].v = true;
			v[0][b].dir = 2;
			v[0][b].prev = &v[a][b];
			// if(b==n) return &v[0][b];
			q.push( state(0,b) );
		}
		//pour A B
		db = min(x,cb);
		da = x-db;
		if(!v[da][db].v){
			v[da][db].v = true;
			v[da][db].dir = 3;
			v[da][db].prev = &v[a][b];
			if(db==n) return &v[da][db];
			q.push( state(da,db) );
		}
		//fill B
		if(!v[a][cb].v){
			v[a][cb].v = true;
			v[a][cb].dir = -1;
			v[a][cb].prev = &v[a][b];
			// if(a==n) return &v[a][cb];
			q.push( state(a,cb) );
		}
		//empty B
		if(!v[a][0].v){
			v[a][0].v = true;
			v[a][0].dir = -2;
			v[a][0].prev = &v[a][b];
			// if(a==n) return &v[a][cb];
			q.push( state(a,0) );
		}
		//pour B A
		da = min(x,ca);
		db = x-da;
		if(!v[da][db].v){
			v[da][db].v = true;
			v[da][db].dir = -3;
			v[da][db].prev = &v[a][b];
			if(db==n) return &v[da][db];
			q.push( state(da,db) );
		}
	}
	//cout << "FAIL" << endl;
}
void print(node* p){
	if(p!=&v[0][0]){
		print(p->prev);
		switch(abs(p->dir)){
			case 1:
				cout << "fill ";
				if(p->dir==1) cout << 'A';
				else cout << 'B';
				break;
			case 2:
				cout << "empty ";
				if(p->dir==2) cout << 'A';
				else cout << 'B';
				break;
			case 3:
				cout << "pour ";
				if(p->dir==3) cout << "A B";
				else cout << "B A";
				break;
			//default: cout << "NO SOLUTION";
		}
		cout << endl;
	}
}
int main(){
	while(cin >> ca >> cb >> n){
		print(bfs());
		cout << "success" << endl;
	}
}
