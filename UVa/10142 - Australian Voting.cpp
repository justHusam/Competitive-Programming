#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, cnt[20], vis[20], vs;
char s[20][81], ss[111];
vector<vector<int> > g;
vector<int> res;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; ++i)
			gets(s[i]);
		g.clear();
		while (gets(ss) > 0 && strlen(ss)) {
			vector<int> v;
			for (char *z = strtok(ss, " "); z != NULL; z = strtok(NULL, " "))
				v.push_back(atoi(z) - 1);
			g.push_back(v);
		}
		++vs;
		res.clear();
		while (true) {
			for (int i = 0; i < n; ++i)
				cnt[i] = 0;
			int all = 0;
			for (size_t i = 0; i < g.size(); ++i)
				for (size_t j = 0; j < g[i].size(); ++j)
					if (vis[g[i][j]] != vs) {
						++cnt[g[i][j]];
						++all;
						break;
					}
			int need = all / 2 + 1, win = -1, mn = 2e9, w = 0;
			for (int i = 0; i < n; ++i) {
				if (vis[i] == vs)
					continue;
				if (cnt[i] >= need)
					win = i;
				++w;
				mn = min(mn, cnt[i]);
			}
			if (win != -1) {
				res.push_back(win);
				break;
			}
			vector<int> del;
			for (int i = 0; i < n; ++i)
				if (vis[i] != vs && cnt[i] == mn)
					del.push_back(i);
			if ((int) del.size() == w) {
				res = del;
				break;
			}
			for (size_t i = 0; i < del.size(); ++i)
				vis[del[i]] = vs;
		}
		for (size_t i = 0; i < res.size(); ++i)
			puts(s[res[i]]);
		if (t != 0)
			puts("");
	}
	return 0;
}
