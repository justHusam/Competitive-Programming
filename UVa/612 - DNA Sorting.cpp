#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int calc(const string&s) {
	int res = 0;
	for (size_t i = 0; i < s.length(); ++i)
		for (size_t j = i + 1; j < s.length(); ++j)
			if (s[i] > s[j])
				++res;
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<string> v(m);
		char s[100];
		vector<pair<int, int> > res(m);
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			v[i] = string(s);
			res[i] = make_pair(calc(s), i);
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < m; ++i)
			puts(v[res[i].second].c_str());
		if (T != 0)
			puts("");
	}
	return 0;
}
