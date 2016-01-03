import java.util.*;
import java.io.*;

public class Treap {

	int key, value, result;
	int prio; boolean cache;
	Treap[] child = new Treap[2]; // 0 = LEFT, 1 = RIGHT

	public Treap(int key, int value) {
		this.key = key;
		this.value = value;
		this.cache = false;
		this.prio = (int) (Math.random() * Integer.MAX_VALUE);
		child[0] = child[1] = null;
	}

	Treap rotate(int side) {
		Treap son = this.child[1 - side];
		this.child[1 - side] = son.child[side];
		son.child[side] = this;
		this.cache = son.cache = false;
		return son;
	}

	Treap find(int key) {
		if (key == this.key) return this;
		if (child[key < this.key ? 0 : 1] == null)
			return null;
		return child[key < this.key ? 0 : 1].find(key);
	}

	Treap insert(int key, int value) {
		if (key == this.key) {
			this.value = value;
			return this;
		}
		int side = key < this.key ? 0 : 1;
		if (child[side] == null)
			child[side] = new Treap(key, value);
		else
			child[side] = child[side].insert(key, value);
		Treap root = this.prio < child[side].prio ? rotate(1 - side) : this;
		root.cache = false;
		return root;
	}

	Treap erase(int key) {
		if (key == this.key) {
			if (child[0] == null && child[1] == null)
				return null;
			Treap root = this;
			if      (child[0] == null) root = root.rotate(0);
			else if (child[1] == null) root = root.rotate(1);
			else root = rotate(child[0].prio < child[1].prio ? 0 : 1);
			root.cache = false;
			return root;
		}
		else {
			int side = key < this.key ? 0 : 1;
			child[side] = child[side].erase(key);
			this.cache = false;
			return this;
		}
	}

	// nth element
	Treap findByOrder(int n) {
		int children = child[0].countChildren();
		if (n < children) return child[0].findByOrder(n);
		else if (n > children) return child[0].findByOrder(n - children - 1);
		else return this;
	}

	int countChildren() {
		if (!cache) {
			int left = (child[0] == null ? 0 : child[0].countChildren());
			int right = (child[1] == null ? 0 : child[1].countChildren());
			result = left + right + 1;
			cache = true;
		}
		return result;
	}

}