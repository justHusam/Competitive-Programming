#include <bits/stdc++.h>
using namespace std;

bool alpha(char a) {
	return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {
		int res = 0;
		for (size_t i = 0; i <= s.length(); ++i) {
			if (alpha(s[i]))
				++res;
			while (alpha(s[i]) && i < s.length())
				++i;
		}
		printf("%d\n", res);
	}
	return 0;
}
