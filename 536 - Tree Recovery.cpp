/**
	UVa 536 - Tree Recovery
	by Rico Tiongson
	Submitted: August 25, 2013
	Accepted 0.012s C++
	O(logn) time
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
string a, b;
struct node{
	char data;
	node *L, *R;
	int lb, rb;
	node(): L(NULL), R(NULL), data(), lb(-1), rb(b.size()) {}
	node( char c ): L(NULL), R(NULL), data(c), lb(-1), rb(b.size()) {}
};
int i, par, ch, cmp;
map<char,int> m;
vector<node*> v;
node *p, *r;
void postOrder( node* x ){
	if( x==NULL ) return;
	postOrder( x->L );
	postOrder( x->R );
	cout << x->data;
}
// void preOrder( node* x ){
	// if( x==NULL ) return;
	// cout << x->data;
	// preOrder( x->L );
	// preOrder( x->R );
// }
int main(){
	while( cin >> a >> b ){
		m.clear();
		v.clear();
		for( i=0; i<b.size(); ++i ) m[ b[i] ] = i;
		for( i=0; i<a.size(); ++i ){
			p = new node( a[i] );
			redo:
			if( v.empty() ){
				// if( i==0 ) root = p;
				v.push_back( p );
				continue;
			}
			par = m[v.back()->data];
			ch = m[p->data];
			cmp = par-ch;
			if( cmp>0 ){
				// try putting left
				if( v.back()->L==NULL && v.back()->lb<ch ){
					// good, put as left node
					v.back()->L = p;
					p->lb = v.back()->lb;
					p->rb = par;
					v.push_back(p);
					continue;
				}
				// not good, pop until good
				v.pop_back();
				goto redo;
			}
			else if( cmp<0 ){
				// try putting right
				if( v.back()->R==NULL && v.back()->rb>ch ){
					// good, put as right node
					v.back()->R = p;
					p->lb = par;
					p->rb = v.back()->rb;
					v.push_back(p);
					continue;
				}
				v.pop_back();
				goto redo;
			}
		}
		// cout << v.front()->lb << " " << v.front()->rb << endl;
		// print le root
		postOrder( v.front() );
		cout << endl;
	}
}
