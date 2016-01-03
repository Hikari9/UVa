#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 50001;
const int logN = log(N);

// stores index of min or max
int table[N][logN + 1];
void build(int arr[], int n) {
	for (int i = 0; i < n; i++)
		table[i][0] = i;
	for (int j = 0; (2 << j) <= n; j++) {
		for (int i = 0; i + (2 << j) <= n; i++) {
			int cur = table[i][j];
			int next = table[i + (1 << j)][j];
			// use a[cur] >= a[next] for max query
			table[i][j + 1] = (arr[cur] <= arr[next] ? cur : next);
		}
	}
}
// returns min[a...b]
int query(int arr[], int a, int b) {
	int k = 31 - __builtin_clz(b-a+1); // = log(e-s+1);
	int i = table[s][k];
	int j = table[b - (1<<k) + 1][k];
	return min(arr[i], arr[j]);
}

int main() {
	
}