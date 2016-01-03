#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
const int N = 100005;

// for treap operations
struct node {
	int key, prio, size, lazy;
	node *left, *right, *par;
	node(int k): key(k), lazy(0), prio(rand()), size(1), par(NULL), left(NULL), right(NULL) {}
};

node *map[N];
struct treap {
	node *root;
	treap(node *r = NULL): root(r) {
		srand(time(NULL));
	}
	// Requests
	int size() const { return size(root); }
	int size(node *p) const { return p ? p->size : 0; }
	void push(node *p) const {
		if (p && p->lazy) {
			p->key -= p->lazy;
			// cout << "Pushing: " << p->key << " " << p->lazy << endl;
			if (p->left) p->left->lazy += p->lazy;
			if (p->right) p->right->lazy += p->lazy;
			p->lazy = 0;
		}
	}
	void pull(node *p) const {
		if(p) {
			p->size = size(p->left) + size(p->right) + 1;
			if (p->left) p->left->par = p;
			if (p->right) p->right->par = p;
		}
	}
	// Rotation
	void rotateLeft(node *&p) {
		node *son = p->left;
		p->left = son->right;
		son->right = p;
		p = son; // refer to parent's child
		pull(p->right); pull(p);
	}
	void rotateRight(node *&p) {
		node *son = p->right;
		p->right = son->left;
		son->left = p;
		p = son; // refer to parent's child
		pull(p->left); pull(p);
	}
	void insert(int k, int v) {
		insert(root, k, v);
	}
	void insert(node *&p, int k, int v) {
		push(p);
		if (!p) {
			map[v] = p = new node(k);
		} else if (k < p->key || (k == p->key && size(p->left) < size(p->right))) {
			insert(p->left, k, v);
			if (p->prio < p->left->prio)
				rotateLeft(p);
		} else {
			insert(p->right, k, v);
			if (p->prio < p->right->prio)
				rotateRight(p);
		}
		pull(p);
	}
	void eraseDown(node *&p) {
		push(p);
		if (!p) return;
		// cout << "Checking: " << p->key << endl;
		if (p->left && p->right) {
			// cout << "Sifting..." << endl;
			if (p->left->prio < p->right->prio) {
				rotateLeft(p);
				eraseDown(p->right);
			}
			else {
				rotateRight(p);
				eraseDown(p->left);
			}
			// print();
		}
		else {
			node *him = p;
			// cout << "Impact" << endl;
			if (p->left) p = p->left;
			else         p = p->right;
			// delete him;
		}
		pull(p);
	}
	// decrement all keys of at least k
	// merge k and k-1 if possible
	void decrement(int k) { decrement(root, k); }
	// add a lazy flag to nodes
	void decrement(node *&p, int k) {
		push(p);
		// cout << "P: " << p << endl;
		if (!p) return;
		// cout << "Decrementing: " << p->key << endl;
		if (k <= p->key) {
			p->key--;
			if (p->right) {
				p->right->lazy++;
			}
			decrement(p->left, k);
		} else {
			decrement(p->right, k);
		}
	}
	// count all nodes with k <= p->key
	int count(int k) const { return count(root, k); }
	int count(node *p, int k) const {
		push(p);
		if (!p) return 0;
		if (k <= p->key) return 1 + size(p->right) + count(p->left, k);
		if (k > p->key) return count(p->right, k);
	}
	void print() const {
		print(root);
		cout << endl;
	}
	void print(node *p) const {
		push(p);
		if (!p) return;
		cout << " " << p->key << "/" << (p->prio%10) << " ";
		cout << "[";
		print(p->left);
		cout << ":";
		print(p->right);
		cout << "]";
	}
};

int n, q, c, x;
treap tree;

node *stack[N * 6]; int top;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		tree.insert(x, i);
	}
	while (q--) {
		cin >> c >> x;
		// cout << "Command: " << c << " " << x << endl;
		if (c == 1) { // increase key by 1
			top = 0;
			for (node *p = map[x]; p; p = p->par)
				stack[top++] = p;
			for (int i = top - 1; i >= 0; --i)
				tree.push(stack[i]);
			int k = map[x]->key;
			// cout << "ERASE: " << k << endl;
			// tree.print();
			if (map[x] == tree.root) {
				// cout << "Erasing root..." << endl;
				tree.eraseDown(tree.root);
			}
			else if (map[x]->par->left == map[x]) {
				// cout << "Erasing parent left..." << endl;
				tree.eraseDown(map[x]->par->left);
			}
			else {
				// cout << "Erasing parent right..." << endl;
				tree.eraseDown(map[x]->par->right);
			}
			for (int i = top - 2; i >= 0; --i)
				tree.pull(stack[i]);
			tree.insert(k + 1, x);
		}
		else if (c == 2) {
			cout << tree.count(x) << '\n';
		}
		else {
			tree.decrement(x);
		}
		// tree.print();
	}
	cout << flush;
}