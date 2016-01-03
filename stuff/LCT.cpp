#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
	Node *left, *right, *parent;
	bool flip;
	Node(): left(NULL), right(NULL), parent(NULL), flip(false) {}
};

void push(Node *x) {
	if (!x->flip) return;
	x->flip = false;
	swap(x->left, x->right);
	if (x->left)
		x->left->flip ^= true;
	if (x->right)
		x->right->flip ^= true;
}

bool isRoot(Node *x) {
	return !x->parent || (x->parent->left != x && x->parent->right != x);
}

void connect(Node *ch, Node *p, bool l) {
	if (l) p->left = ch;
	else p->right = ch;
	if (ch) ch->parent = p;
}

void rotate(Node *x) {
	Node *p = x->parent;
	Node *g = p->parent;
	bool isRootP = isRoot(p);
	bool left = (x == p->left);
	connect(left ? x->right : x->left, p, left);
	if (!isRootP) connect(x, g, p == g->left);
	else x->parent = g;
}

void splay(Node* x) {
	while (!isRoot(x)) {
		Node *p = x->parent;
		Node *g = p->parent;
		if (!isRoot(p)) push(g);
		push(p); push(x);
		if (!isRoot(p))
			rotate((x == p->left) == (p == g->left) ? p : x);
		rotate(x);
	}
	push(x);
}


Node* expose(Node *x) {
	Node *last = NULL;
	for (Node *y = x; y; y = y->parent) {
		splay(y);
		y->left = last;
		last = y;
	}
	splay(x);
	return last;
}

Node* findRoot(Node *x) {
	expose(x);
	while (x->right) {
		x = x->right;
		push(x);
	}
	return x;
}

bool connected(Node *x, Node *y) {
	if (x == y) return true;
	expose(x); expose(y);
	return x->parent != NULL;
}

void link(Node *x, Node *y) {
	if (findRoot(x) == findRoot(y))
		return;
	expose(x);
	x->flip ^= true;
	x->parent = y;
}

void cut(Node *x, Node *y) {
	expose(x);
	x->flip ^= true;
	expose(y);
	if (y->right == x || x->left || x->right)
		return;
	y->right->parent = y->right = NULL;
}

Node nodes[100005];
int n, m, a, b, color[100005];
vector<int> adj[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		link(&nodes[a], &nodes[b]);
	}
	cin >> m;
	while (m--) {
		cin >> a >> b;
		if (a) {
			color[b] ^= 1;
			for (int v : adj[u]) {
				if (color[v] != color[a])
					cut(&nodes[b], &nodes[v]);
				else
					link(&nodes[b], &nodes[v]);
			}
		}
		else {
			cout << connected(b)
		}
	}
	cout << flush;
}