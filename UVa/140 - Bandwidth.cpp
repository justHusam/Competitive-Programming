#include <bits/stdc++.h>
using namespace std;

const int N = 8;
char z[1111];
vector<int> g[N];
int hs[26];
vector<char> all;

int get(int u) {
	if (hs[u] == -1) {
		hs[u] = all.size();
		all.push_back(u + 'A');
	}
	return hs[u];
}

int calc(int v, string &s) {
	int mx = 0;
	int a = s.find(all[v]);
	for (size_t i = 0; i < g[v].size(); ++i)
		mx = max(mx, abs(a - (int) s.find(all[g[v][i]])));
	return mx;
}

int main(int argc, char **argv) {
	while (scanf("%s", z) && z[0] != '#') {
		string s = z;
		for (int i = 0; i < N; ++i)
			g[i].clear();
		memset(hs, -1, sizeof hs);
		all.clear();
		for (size_t i = 0; i < s.size(); ++i) {
			int u = get(s[i] - 'A');
			for (i += 2; i < s.size() && s[i] != ';'; ++i) {
				int v = get(s[i] - 'A');
				g[u].push_back(v);
				g[v].push_back(u);

			}
		}
		string p = "";
		for (size_t i = 0; i < all.size(); ++i)
			p += all[i];
		sort(p.begin(), p.end());
		int mn = 2e9;
		string res = "";
		do {
			int mx = 0;
			for (size_t i = 0; i < p.size(); ++i)
				mx = max(mx, calc(i, p));
			if (mx < mn || (mx == mn && p < res)) {
				mn = mx;
				res = p;
			}
		} while (next_permutation(p.begin(), p.end()));
		for (size_t i = 0; i < res.size(); ++i)
			printf("%c ", res[i]);
		printf("-> %d\n", mn);
	}
	return 0;
}
