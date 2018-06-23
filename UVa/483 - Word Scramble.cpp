#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {
		int j = 0;
		string res = "";
		for (size_t i = 0; i < s.length(); i++) {
			if (isspace(s[i])) {
				for (int k = i - 1; k >= j; k--)
					res += s[k];
				j = i + 1;
				cout << res << " ";
				res = "";
			} else {
				if (i + 1 == s.length()) {
					for (int c = i; c >= j; c--)
						res += s[c];
					cout << res << endl;
				}
			}
		}
	}
	return 0;
}
