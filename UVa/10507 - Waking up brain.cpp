#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, id;
char s[10];
set<int> w, st;
map<char, int> hs;
vector<int> g[26];

int idx(char c) {
	if (hs.find(c) == hs.end())
		hs[c] = id++;
	return hs[c];
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		scanf("%d%s", &m, s);
		hs.clear();
		id = 0;
		w.clear();
		for (int i = 0; s[i]; ++i)
			w.insert(idx(s[i]));
		for (int i = 0; i < n; ++i)
			g[i].clear();
		while (m-- != 0) {
			scanf("%s", s);
			int u = idx(s[0]), v = idx(s[1]);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = 0;
		while ((int) w.size() != n) {
			st.clear();
			++res;
			for (int i = 0; i < n; ++i)
				if (w.find(i) == w.end()) {
					int can = 0;
					for (size_t j = 0; j < g[i].size() && can < 3; ++j)
						can += w.find(g[i][j]) != w.end();
					if (can >= 3)
						st.insert(i);
				}
			if (!st.size())
				break;
			w.insert(st.begin(), st.end());
		}
		if ((int) w.size() != n)
			puts("THIS BRAIN NEVER WAKES UP");
		else
			printf("WAKE UP IN, %d, YEARS\n", res);
	}
	return 0;
}
