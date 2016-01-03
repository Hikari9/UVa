#include <iostream>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define data get_metadata
#define left get_l_child
#define right get_r_child

using namespace std;
using namespace __gnu_pbds;

template<class cnode, class node, class cmp, class alloc>

struct rmq_update {
	typedef int metadata_type;
	rmq_update() {}
	void operator() (node it, cnode null) const {
		(int&) it.data() = (**it).second; // default value
		if (it.left() != null)
			(int&) it.data() = min(it.data(), it.left().data());
		if (it.right() != null)
			(int&) it.data() = min(it.data(), it.right().data());
	}
};

typedef tree<int, int, less<int>, splay_tree_tag, rmq_update> Tree;

Tree rmq, left, right;
int n, q, x, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x, rmq.insert(make_pair(i, x));
	cin >> q;
	while (q--) {
		cin >> a >> b;
		rmq.split(b,    right);
		rmq.split(a - 1, left);
		cout << left.node_begin().data() << '\n';
		rmq.join(left);
		rmq.join(right);
	}
	cout << flush;
}