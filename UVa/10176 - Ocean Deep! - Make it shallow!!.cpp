#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 131071;
string s;

int main(int argc, char **argv) {
	char ch;
	while (scanf(" %c", &ch) != EOF) {
		s = ch;
		while (true) {
			char ch;
			scanf(" %c", &ch);
			if (ch == '#')
				break;
			s += ch;
		}
		ll res = 0, p = 1;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == '1')
				res = (res + p) % M;
			p = (p << 1) % M;
		}
		if (res == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}