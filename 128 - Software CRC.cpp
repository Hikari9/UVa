#include <iostream>
#include <cstdio>
#include <cstring>
#define g 34943
#define g2 30593
using namespace std;

char s[1025];

int main() {
	while (gets(s) && s[0] != '#') {
		int len = strlen(s);
		int m = 0;
		int two = g2;
		for (int i = len - 1; i >= 0; --i) {
			m = (m + (two * s[i]) % g) % g;
			two = (two << 8) % g;
		}
		int x = (g - m) % g;
		printf("%02X %02X\n", x >> 8, x & ((1 << 8) - 1));
	}
}
