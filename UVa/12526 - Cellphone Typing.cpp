#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> node(26, -1), E;
vector<vector<int> > g;
char s[100000][82];

void insert(char *s) {
	int cur = 0, n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (g[cur][s[i] - 'a'] == -1) {
			g[cur][s[i] - 'a'] = g.size();
			g.push_back(node);
			E.push_back(0);
		}
		cur = g[cur][s[i] - 'a'];
	}
	++E[cur];
}

int calc(char *s) {
	int res = 0, cur = g[0][s[0] - 'a'], n = strlen(s);
	for (int i = 1; i < n; ++i) {
		int v = 0;
		for (int j = 0; j < 26 && v < 2; ++j)
			v += g[cur][j] != -1;
		if (v == 1 && E[cur] == 0)
			++res;
		cur = g[cur][s[i] - 'a'];
	}
	return n - res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		g.clear();
		g.push_back(node);
		E.clear();
		E.push_back(0);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			insert(s[i]);
		}
		double res = 0;
		for (int i = 0; i < n; ++i)
			res += calc(s[i]);
		res /= n;
		printf("%.2lf\n", res);
	}
	return 0;
}
