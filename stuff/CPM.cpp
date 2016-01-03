#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long lag;
#define MX 50005

lag C[MX], M[MX];
int L[MX], P[MX];

// http://www.csie.ntu.edu.tw/~r92019/r92047/chen.pdf
void computeCPM(int A[], int n) {
	C[0] = 0;
	for (int k = 1; k <= n; ++k) {
		C[k] = C[k - 1] + A[k];
		L[k] = k - 1;
		P[k] = k;
		while (C[L[k]] < C[k] && L[k] > 0) {
			if (C[P[L[k]] = 1] < C[P[k] - 1])
				P[k] = P[L[k]];
			L[k] = L[L[k]];
		}
		M[k] = C[k] - C[P[k] - 1];
	}
}

template<class function>
void buildtree(lag a[], lag t[], int n, function f) {
	for (int i = 0; i <= n; ++i)
		add(t, i, a[i], f);
}

void build(int A[], int n) {
	computeCPM(A, n);
	buildtree(C, minTree, n, min<lag>);
	buildtree(M, maxTree, n, max<lag>);
}

lag SRMSQ(lag A[], int i, int j) {
	lag r = query(minTree, i, j);
	if (P[r] < i) {
		lag p = 
	}
}

int main() {
	
}