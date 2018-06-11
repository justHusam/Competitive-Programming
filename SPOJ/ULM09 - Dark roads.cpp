#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, c;
	bool operator<(const edge&e) const {
		return c < e.c;
	}
} e[200000];

int p[200000];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0)) {
		for (int i = 0; i < n; ++i)
			p[i] = i;
		int res = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
			res += e[i].c;
		}
		sort(e, e + m);
		int cnt = 0;
		for (int i = 0; i < m && cnt != n - 1; ++i) {
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a != b) {
				p[a] = b;
				res -= e[i].c;
				++cnt;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
