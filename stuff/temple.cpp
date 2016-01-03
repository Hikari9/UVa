#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define data get_metadata
#define left get_l_child
#define right get_r_child
#define KEY (**it).first
#define VALUE (**it).second
#define LVALUE (**it.left()).second
#define RVALUE (**it.right()).second
#define TEMP template <typename cnode, typename node>

using namespace std;
using namespace __gnu_pbds;
const int N = 100001;

struct key {
	int value, *lazy;
	key(int x): value(x), lazy(new int) {}
	int operator()() const { return value - *lazy; }
	bool operator < (const key& k) const {
		int val1 = (*this) ();
		int val2 = k ();
		if (val1 == val2) return value < k.value;
		return val1 < val2;
	}
	friend ostream& operator << (ostream& out, const key& k) {
		return out << "(" << k.value << "," << *k.lazy << ")";
	}
};

struct value {
	int lazy, id, size, freq;
	value(int id): lazy(0), id(id), size(1), freq(1) {}
	friend ostream& operator << (ostream& out, const value& v) {
		return out << v.id;
	}
};

TEMP void pull(node it, cnode null);
TEMP void push(node it, cnode null);
TEMP int size(node it, cnode null);

template <typename cnode, typename node, typename cmp, typename alloc>
struct node_update {
	typedef null_type metadata_type;
	void operator() (node it, cnode null) const {
		::push(it, null);
		::pull(it, null);
	}
};

typedef tree<key, value, less<key>, splay_tree_tag, node_update> Tree;
Tree::node_iterator Map[N], par[N];
Tree t;

TEMP void push(node it, cnode null) {
	if (it == null) return;
	int& l = VALUE.lazy;
	if (l) {
		*KEY.lazy += l;
		if (it.left() != null)     LVALUE.lazy += l;
		if (it.right() != null)    RVALUE.lazy += l;
		l = 0;
	}
}

TEMP void pull(node it, cnode null) {
	VALUE.size = size(it.left(), null) + size(it.right(), null) + VALUE.freq;
	if (it.left() != null)
		par[LVALUE.id] = it;
	if (it.right() != null)
		par[RVALUE.id] = it;
	Map[VALUE.id] = it;
}

TEMP int size(node it, cnode null) {
	if (it == null) return 0;
	return VALUE.size;
}

TEMP void pullUp(node it, cnode begin, cnode null) {
	while (it != begin) {
		pull(it, null);
		it = par[VALUE.id];
	}
	pull(begin, null);
}

Tree::node_iterator *stack[N];
TEMP void pushDown(node it, cnode begin, cnode null) {
	int top = 0;
	while (it != begin) {
		stack[top++] = &it;
		it = par[VALUE.id];
	}
	while (top > 0)
		push(*stack[--top], null);
}

TEMP int count(int k, node it, cnode null) {
	if (it == null) return 0;
	push(it, null);
	if (k <= KEY()) return VALUE.freq + size(it.right(), null) + count(k, it.left(), null);
	return count(k, it.right(), null);
}
int count(int k) { return count(k, t.node_begin(), t.node_end()); }

TEMP void decrement(int k, node it, cnode null) {
	if (it == null) return;
	push(it, null);
	if (k <= KEY()) {
		(*((key&)KEY).lazy)++;
		if (it.right() != null)
			RVALUE.lazy++;
		decrement(k, it.left(), null);
	} else {
		decrement(k, it.right(), null);
	}
}
void decrement(int k) {decrement(k, t.node_begin(), t.node_end());}


int n, q, c, x;

TEMP void print(node it, cnode null) {
	if (it == null) return;
	print(it.left(), null);
	cout << KEY() << "/" << VALUE <<  "/" << VALUE.size << "(";
	print(it.right(), null);
	cout << ")";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		pair<Tree::iterator, bool> result = t.insert(make_pair(x, i));
		// pull up
		if (!result.second) {
			result.first->second.freq++;
			pullUp(Map[result.first->second.id], t.node_begin(), t.node_end());
		}
	}
	while (q--) {
		cin >> c >> x;
		
		if (c == 1) { // increment key
			pushDown(Map[x], t.node_begin(), t.node_end());
			key k = (**Map[x]).first;
			value v = (**Map[x]).second;
			t.erase(*Map[x]);
			k.value++;
			v.freq = 1;
			pair<Tree::iterator, bool> result = t.insert(make_pair(k, v));
			pushDown(Map[x], t.node_begin(), t.node_end());
			// pull up
			if (!result.second) {
				result.first->second.freq++;
				pullUp(Map[result.first->second.id], t.node_begin(), t.node_end());
			}
		} else if (c == 2) {
			cout << count(x) << '\n';
		} else {
			decrement(x);
		}
		// print(t.node_begin(), t.node_end()); cout << endl;

	}
	cout << flush;
}