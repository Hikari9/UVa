// 10197 - Learning Portuguese
// By Rico Tiongson
// Ad Hoc + unsigned char

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#define cstring const string&
#define endl '\n'

string uproot(cstring verb) {
	return verb.substr(0, verb.length() - 2);
}

char tv(cstring verb) {
	return verb[verb.length() - 2];
}

int num(cstring verb) {
	switch (tv(verb)) {
		case 'a': return 1;
		case 'e': return 2;
		case 'i': return 3;
		default: return 0;
	}
}

bool invalid(cstring verb) {
	return verb.length() < 2 || num(verb) == 0 || verb[verb.length() - 1] != 'r';
}

template<class str>
void print(str title, cstring message) {
	cout.width(10);
	cout << left << title << message << endl;
}

unsigned char nos[] = "nos";
unsigned char vos[] = "vos";

int main() {
	nos[1] = 243;
	vos[1] = 243;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string verb, english;
	bool first = true;
	while (cin >> verb) {
		getline(cin, english);
		for (int i = english.size() - 1; i >= 0; --i) {
			if (english[i] != ' ') {
				if (i != english.size() - 1)
					english = english.substr(0, i + 1);
				break;
			}
		}
		for (int i = 0; i < english.size(); ++i) {
			if (english[i] != ' ') {
				if (i)
					english = english.substr(i);
				break;
			}
		}
		if (first) first = false;
		else cout << endl;
		cout << verb << " (to " << english << ")" << endl;
		if (invalid(verb)) {
			cout << "Unknown conjugation" << endl;
		}
		else {
			string root = uproot(verb);
			print("eu", root + "o");
			print("tu", num(verb) < 3 ? root + tv(verb) + "s" : root + "es");
			print("ele/ela", num(verb) < 3 ? root + tv(verb) : root + "e");
			print(nos, root + tv(verb) + "mos");
			print(vos, root + tv(verb) + (num(verb) < 3 ? "is" : "s"));
			print("eles/elas", (num(verb) < 3 ?  root + tv(verb) + "m" : root + "em"));
		}
	}
	cout << flush;
}