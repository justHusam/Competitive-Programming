#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

map<char, char> x, y;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	string s = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	size_t idx = 0;
	for (char a = 'A'; idx < 26; ++idx, ++a)
		x[s[idx]] = a;
	for (char a = 'a'; idx < 52; ++idx, ++a)
		x[s[idx]] = a;
	map<char, char>::iterator it;
	for (it = x.begin(); it != x.end(); ++it)
		y[it->second] = it->first;
	while (t-- != 0) {
		string s, in;
		cin >> in;
		for (int i = 0; in[i]; ++i)
			s += x[in[i]];
		sort(s.begin(), s.end());
		do {
			for (size_t i = 0; i < s.size(); ++i)
				putchar(y[s[i]]);
			puts("");
		} while (next_permutation(s.begin(), s.end()));
	}
	return 0;
}
