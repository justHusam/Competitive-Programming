#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 105;
char x[N], y[N];

inline map<string, string> get(const string &s) {
	map<string, string> hs;
	int n = s.length();
	if (n == 2)
		return hs;
	for (int a = 1; a < n; ++a) {
		string x = "", y = "";
		while (s[a] != ':')
			x += s[a++];
		++a;
		while (s[a] != ',' && s[a] != '}')
			y += s[a++];
		hs[x] = y;
	}
	return hs;
}

int print(char ch, const vector<string>&v) {
	if (v.empty())
		return 0;
	putchar(ch);
	for (size_t i = 0; i < v.size(); ++i) {
		if (i != 0)
			putchar(',');
		printf("%s", v[i].c_str());
	}
	putchar('\n');
	return 1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", x, y);
		map<string, string> v = get(x);
		map<string, string> g = get(y);
		map<string, string>::iterator it;
		vector<string> a, b, c;
		for (it = v.begin(); it != v.end(); ++it)
			if (g.find(it->first) == g.end())
				a.push_back(it->first);
			else if (g[it->first] != it->second)
				b.push_back(it->first);
		for (it = g.begin(); it != g.end(); ++it)
			if (v.find(it->first) == v.end())
				c.push_back(it->first);
		int sum = 0;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		sum += print('+', c);
		sum += print('-', a);
		sum += print('*', b);
		if (sum == 0)
			puts("No changes");
		putchar('\n');
	}
	return 0;
}
