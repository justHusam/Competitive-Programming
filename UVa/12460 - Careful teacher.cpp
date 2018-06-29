#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4;
int n, p[N];
vector<pair<string, int> > g[N];
char s[N];
map<string, int> hs;

inline bool check(const string &a, const string &b) {
	int res = 0;
	for (int i = 0; i < (int) a.size() && res <= 1; ++i)
		if (a[i] != b[i])
			++res;
	return res <= 1;
}

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

inline int getNode(const string &s) {
	map<string, int>::iterator it = hs.find(s);
	if (it == hs.end())
		return -1;
	return it->second;
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && strcmp(s, "--")) {
		g[strlen(s)].push_back(make_pair(s, n));
		hs[s] = n++;
	}
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (int i = 0; i < N; ++i)
		for (size_t j = 0; j < g[i].size(); ++j)
			for (size_t k = j + 1; k < g[i].size(); ++k)
				if (check(g[i][j].first, g[i][k].first))
					p[find(g[i][k].second)] = find(g[i][j].second);
	while (scanf("%s", s) != EOF) {
		int u = getNode(s);
		scanf("%s", s);
		int v = getNode(s);
		if (u != -1 && v != -1 && find(u) == find(v))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
