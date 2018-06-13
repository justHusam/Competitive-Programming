#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator<(const edge&e) const {
		return c < e.c;
	}
};

const int N = 1000;
int n, m, p[N];
vector<edge> e;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		e.clear();
		ll all = 0;
		while (m-- != 0) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			e.push_back(edge(u, v, c));
			all += c;
		}
		sort(e.begin(), e.end());
		int w = 0;
		for (size_t i = 0; i < e.size() && w != n - 1; ++i) {
			int a = find(e[i].u);
			int b = find(e[i].v);
			if (a != b) {
				p[a] = b;
				all -= e[i].c;
				++w;
			}
		}
		printf("%lld\n", all);
	}
	return 0;
}
