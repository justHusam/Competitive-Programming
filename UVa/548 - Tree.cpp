#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[111111];
vector<int> a, b;
int n, hs[10001], idx, best, mn;
map<int, int> g;

void build(int s, int e, int p) {
	g[p] = b[idx];
	if (s == e)
		return;
	int m = hs[b[idx]];
	if (m + 1 <= e) {
		--idx;
		build(m + 1, e, p * 2 + 1);
	}
	if (m - 1 >= s) {
		--idx;
		build(s, m - 1, p * 2);
	}
}

void calc(int p, int w) {
	if (w > best)
		return;
	map<int, int>::iterator L = g.find(p * 2), R = g.find(p * 2 + 1);
	if (L == g.end() && R == g.end()) {
		if (w < best) {
			best = w;
			mn = g[p];
		} else if (w == best)
			mn = min(mn, g[p]);
		return;
	}
	if (L != g.end())
		calc(p * 2, w + g[p * 2]);
	if (R != g.end())
		calc(p * 2 + 1, w + g[p * 2 + 1]);
}

int main(int argc, char **argv) {
	while (gets(s) > 0) {
		a.clear();
		b.clear();
		for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " ")) {
			a.push_back(atoi(z));
			hs[a.back()] = a.size() - 1;
		}
		n = a.size();
		b.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		idx = n - 1;
		g.clear();
		build(0, n - 1, 1);
		best = mn = 2e9;
		calc(1, g[1]);
		printf("%d\n", mn);
		getchar();
	}
	return 0;
}
