#include <bits/stdc++.h>
using namespace std;

struct node {
	int w;
	char app[22], fix[22];
};

struct state {
	int w;
	bitset<20> mask;
	state(int w, bitset<20> msk) :
			w(w), mask(msk) {
	}
	bool operator <(const state & e) const {
		return w > e.w;
	}
};

int n, m;
bool vis[1 << 20];

bool check(const bitset<20> & msk, const char *s) {
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0')
			continue;
		if (s[i] == '+' && !msk[i])
			return false;
		if (s[i] == '-' && msk[i])
			return false;
	}
	return true;
}

bitset<20> apply(const bitset<20> & msk, const char *fix) {
	bitset<20> nw = msk;
	for (int i = 0; i < n; ++i) {
		if (fix[i] == '0')
			continue;
		if (fix[i] == '+')
			nw[i] = 1;
		if (fix[i] == '-')
			nw[i] = 0;
	}
	return nw;
}

int main(int argc, char **argv) {
	int caseN = 1;
	while (scanf("%d%d", &n, &m) > 0 && n != 0) {
		vector<node> g(m);
		for (int i = 0; i < m; ++i)
			scanf("%d%s%s", &g[i].w, g[i].app, g[i].fix);
		priority_queue<state> qu;
		bitset<20> msk;
		msk.set();
		qu.push(state(0, msk));
		memset(vis, false, sizeof vis);
		int res = -1;
		while (!qu.empty()) {
			state e = qu.top();
			qu.pop();
			if ((e.mask.to_ulong() & ((1 << n) - 1)) == 0) {
				res = e.w;
				break;
			}
			if (vis[e.mask.to_ulong()])
				continue;
			vis[e.mask.to_ulong()] = true;
			for (int i = 0; i < m; ++i) {
				if (!check(e.mask, g[i].app))
					continue;
				bitset<20> nw = apply(e.mask, g[i].fix);
				if (vis[nw.to_ulong()])
					continue;
				qu.push(state(e.w + g[i].w, nw));
			}
		}
		printf("Product %d\n", caseN++);
		if (res != -1)
			printf("Fastest sequence takes %d seconds.\n\n", res);
		else
			puts("Bugs cannot be fixed.\n");
	}
	return 0;
}
