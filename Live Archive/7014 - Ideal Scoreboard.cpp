#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int t, h, m, s, f;
	char p;
	bool operator<(const state&e) const {
		if (e.h != h)
			return h < e.h;
		if (e.m != m)
			return m < e.m;
		return s < e.s;
	}
};

int n, p, m, solve[150], solved[15];
vector<state> v;
char z[111];
bool vis[150][15];

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &p, &m) && (n || p || m)) {
		for (int i = 0; i < n; ++i)
			solve[i] = 0;
		for (int i = 0; i < p; ++i)
			solved[i] = 0;
		v.clear();
		v.resize(m);
		for (int i = 0; i < m; ++i) {
			scanf("%d %c%d:%d:%d", &v[i].t, &v[i].p, &v[i].h, &v[i].m, &v[i].s);
			getchar();
			gets(z);
			v[i].f = z[0] == 'Y';
			--v[i].t;
		}
		memset(vis, false, sizeof vis);
		sort(v.begin(), v.end());
		string a, b;
		int all = 0, one = 0, done = 0, out = 0;
		for (int i = 0; i < m; ++i) {
			if (!v[i].f || vis[v[i].t][v[i].p - 'A'])
				continue;
			vis[v[i].t][v[i].p - 'A'] = true;
			if (!solve[v[i].t])
				++one;
			++solve[v[i].t];
			if (solve[v[i].t] == p)
				++all;
			if (!solved[v[i].p - 'A'])
				++done;
			++solved[v[i].p - 'A'];
			if (solved[v[i].p - 'A'] == n)
				++out;
			if (a.empty() && one == n && all == 0 && done == p && out == 0) {
				a += (v[i].h / 10) + '0';
				a += (v[i].h % 10) + '0';
				a += ":";
				a += (v[i].m / 10) + '0';
				a += (v[i].m % 10) + '0';
				a += ":";
				a += (v[i].s / 10) + '0';
				a += (v[i].s % 10) + '0';
			}
			if (a.size() && (all != 0 || out != 0)) {
				b += (v[i].h / 10) + '0';
				b += (v[i].h % 10) + '0';
				b += ":";
				b += (v[i].m / 10) + '0';
				b += (v[i].m % 10) + '0';
				b += ":";
				b += (v[i].s / 10) + '0';
				b += (v[i].s % 10) + '0';
				break;
			}
			if (all > 0 || out > 0)
				break;
		}
		if (a.empty())
			a = "--:--:--";
		if (b.empty())
			b = "--:--:--";
		printf("%s %s\n", a.c_str(), b.c_str());
	}
	return 0;
}
