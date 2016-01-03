/**
	UVa 12347 - Binary Search Tree
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted: 0.039s C++
	O(n) time
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct node;
node *Null;
struct node{
	int data;
	node *left,*right;
	node(){}
	node(int d,node *l,node *r):
		data(d),
		left(l),
		right(r){}
	node(int d):
	data(d),left(Null),right(Null){}//,v(false){}
};
vector<node> v;
int post(node* root){
	if(root->left!=Null)
		cout << post(root->left) << endl;
	if(root->right!=Null)
		cout << post(root->right) << endl;
	return root->data;
}
int main(){
	int n;
	while(cin >> n)
		v.push_back(node(n));
	int front=0;
	stack<node*> d;
	node* p;
	d.push(&v[0]);
	for(int i=1;i<v.size();i++){
		if(v[i].data<d.top()->data){
			d.top()->left = &v[i];
		}
		else{
			do{
				p = d.top();
				d.pop();
				if(d.empty()) break;
			} while(d.top()->data<v[i].data);
			p->right = &v[i];
		}
		d.push(&v[i]);
	}
	cout << post(&v[0]) << endl;
}
