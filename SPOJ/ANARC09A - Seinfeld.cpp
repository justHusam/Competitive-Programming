#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int k = 1;
	string s;
	while (cin >> s && s[0] != '-') {
		int open = 0, res = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '{') {
				++open;
				continue;
			}
			if (open != 0)
				--open;
			else
				++res, ++open;
		}
		printf("%d. %d\n", k++, res + open / 2);
	}
	return 0;
}
