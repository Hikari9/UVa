#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
const int N = 50001;


namespace treap {
	int prio[N], key[N], child[N][2], size, root;

	int newNode(int k, int p) {
		key[size] = k;
		prio[size] = p;
		child[size][0] = child[size][1] = -1;
		return size++;
	}

	int rotate(int node, int s) {
		// child[node][s] becomes new parent
		int son = child[node][s];
		child[node][s] = child[son][!s];
		child[son][!s] = node;
		return son;
	}

	// assume key does not exist
	int insert(int node, int k, int p) {
		if (node == -1) {
			return newNode(k, p);
		}
		int s = (k < key[node] ? 0 : 1);
		int& son = child[node][s];
		son = insert(son, k, p);
		if (prio[node] < prio[son]) {

			return rotate(node, s);
		}
		return node;
	}

	void insert(int k, int p) {
		root = insert(root, k, p);
	}

	void init() {
		size = 0;
		root = -1;
	}
}

map<string, int> id;
const string *match[N];
char in[N]; int n;

void dfs(int u) {
	if (u == -1) return;
	using namespace treap;
	cout << "(";
	dfs(child[u][0]);
	cout << *match[key[u]] << "/" << prio[u];
	dfs(child[u][1]);
	cout << ")";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n, n) {
		id.clear();
		treap::init();
		for (int i = 0; i < n; ++i) {
			cin >> in;
			char *label = strtok(in, "/");
			int prio = atoi(strtok(NULL, "/"));
			id[label] = prio;
		}
		int i = 0;
		for (map<string, int>::iterator it = id.begin(); it != id.end(); ++it, ++i) {
			treap::insert(i, it->second);
			match[i] = &it->first;
		}
		dfs(treap::root);
		cout << '\n';
	}
	cout << flush;
}