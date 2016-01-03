/**
	UVa 122 - Trees on the level
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.015s C++
	O(V) time
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node;
node* Null;
struct node{
	int data;
	node *left,*right;
	node():left(Null),right(Null),data(-1){}
} root,*t;
vector<node*> q;
bool bfs(){
	q.clear();
	q.push_back(&root);
	for(int i=0;i<q.size();i++){
		if(q[i]->data==-1) return false;
		if(q[i]->left!=Null) q.push_back(q[i]->left);
		if(q[i]->right!=Null) q.push_back(q[i]->right);
	}
	return true;
}
int main(){
	char c[500],*p;
	int n;
	bool ok;
	while(cin >> c){
		root = node();
		ok = true;
		do{
			n = atoi(strtok(c,"(),"));
			p = strtok(NULL,"(),");
			t = &root;
			if(p!=NULL){
				for(int i=0;p[i]!='\0';i++){ //dfs
					if(p[i]=='L'){
						if(t->left==Null) t->left = new node;
						t = t->left;
					}
					else{
						if(t->right==Null) t->right = new node;
						t = t->right;
					}
				}
			}
			if(t->data!=-1) ok=false;
			else t->data = n;
		} while(cin >> c,c[1]!=')');
		if(ok) ok = bfs();
		if(ok){
			cout << q[0]->data;
			for(int i=1;i<q.size();i++) cout << ' ' << q[i]->data;
			cout << endl;
		}
		else cout << "not complete" << endl;
	}
}
