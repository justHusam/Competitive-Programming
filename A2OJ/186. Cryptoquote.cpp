#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, T = 1;
	scanf("%d\n", &t);
	while (t-- != 0) {
		string s, m;
		getline(cin, s);
		getline(cin, m);
		map<char, char> hs;
		int i = 0;
		for (char a = 'A'; a <= 'Z'; ++a)
			hs[a] = m[i++];
		hs[' '] = ' ';
		printf("%d ", T++);
		for (size_t i = 0; i < s.length(); ++i)
			putchar(hs[s[i]]);
		putchar('\n');
	}
	return 0;
}
