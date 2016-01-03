// SPOJ ORDERSET - Order Statistics Set
// Treap implementation

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct node {
	// max priority is root
	int key, size, prio; //,value
	node *left, *right;
	node(int key): 
		key(key), size(1), prio(rand()),
		left(NULL), right(NULL) {}
};

struct treap {
	node *root;
	treap(): root(NULL) { srand(time(NULL)); }
	// treap size
	int size() const { return size(root); }
	int size(node *p) const { return p ? p->size : 0; }
	// pull size from children
	void pull(node *&p) {
		if (p) {
			p->size = 1 + size(p->left) + size(p->right);
			// you can add more pullable stuff (like RMQ)
		}
	}
	// switch son and parent from left
	void rotateLeft(node *&par) {
		node *son = par->left;
		par->left = son->right;
		son->right = par;
		par = son;
		pull(par->right);
		pull(par);
	}
	// switch son and parent from right
	void rotateRight(node *&par) {
		node *son = par->right;
		par->right = son->left;
		son->left = par;
		par = son;
		pull(par->left);
		pull(par);
	}
	// insert key k into the treap
	// returns true if k was inserted
	bool insert(int k) { return insert(root, k); }
	bool insert(node *&p, int k) {
		if (!p) { p = new node(k); return true; }
		bool inserted = false;
		if (k < p->key) {
			inserted = insert(p->left, k);
			if (p->prio < p->left->prio)
				rotateLeft(p);
		}
		else if (k > p->key) {
			inserted = insert(p->right, k);
			if (p->prio < p->right->prio)
				rotateRight(p);
		}
		pull(p);
		return inserted;
	}
	// erase key k from the treap
	// returns true if k was erased
	bool erase(int k) { erase(root, k); }
	bool erase(node *&p, int k) {
		if (!p) return false;
		bool erased = false;
		if (k < p->key)      erased = erase(p->left, k);
		else if (k > p->key) erased = erase(p->right, k);
		else {
			erased = true;
			if (p->left && p->right) {
				if (p->left->prio > p->right->prio)
					rotateLeft(p);
				else
					rotateRight(p);
				erase(p, k);
			}
			else {
				node *him = p;
				if (p->left) p = p->left;
				else p = p->right;
				delete him;
			}
		}
		pull(p);
		return erased;
	}
	// find the node with key k
	// returns NULL if does not exist
	node *find(int k) const {
		return find(root, k);
	}
	node *find(node *p, int k) const {
		if (!p) return NULL;
		if (k < p->key) return find(p->left, k);
		else if (k > p->key) return find(p->right, k);
		else return p;
	}
	// find node by order k (1-based)
	// synonymous to kth-element 
	// returns NULL if does not exist
	node *find_by_order(int k) const {
		return find_by_order(root, k);
	}
	node *find_by_order(node *p, int k) const {
		if (!p) return NULL;
		int lsize = size(p->left) + 1;
		if (k == lsize) return p;
		if (k < lsize) return find_by_order(p->left, k);
		return find_by_order(p->right, k - lsize);
	}
	// count nodes with key less than k
	int count_less(int k) const {
		return count_less(root, k);
	}
	int count_less(node *p, int k) const {
		if (!p) return 0;
		if (k < p->key) return count_less(p->left, k);
		if (k == p->key) return size(p->left);
		return size(p->left) + 1 + count_less(p->right, k);
	}
};

int q, x;
char o;
treap tr;
node *n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> o >> x;
		switch(o) {
			case 'I': // insert
				tr.insert(x);
				break;
			case 'D': // erase
				tr.erase(x);
				break;
			case 'K': // kth element
				n = tr.find_by_order(x);
				if (!n) cout << "invalid\n";
				else cout << n->key << "\n";
				break;
			case 'C': // count
				cout << tr.count_less(x) << "\n";
				break;
		}
	}
	cout << flush;
}