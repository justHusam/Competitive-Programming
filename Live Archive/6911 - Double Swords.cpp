#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5, M = 1e6 + 1;
int n, a[N], b[N], c[N], cum[M];
vector<int> s[M], e[M], w;
bool vis[N], in[N], take[M];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 1; i < M; ++i) {
			cum[i] = 0;
			s[i].clear();
			e[i].clear();
			take[i] = false;
		}
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			if (!cum[a[i]])
				++cum[a[i]];
			vis[i] = in[i] = false;
		}
		for (int i = 1; i < M; ++i)
			cum[i] += cum[i - 1];
		int mn = M, mx = 0;
		for (int i = 0; i < n; ++i) {
			int in = cum[c[i]] - cum[b[i] - 1];
			if (in > 1 || (in == 1 && (a[i] < b[i] || a[i] > c[i])))
				continue;
			s[b[i]].push_back(i);
			e[c[i]].push_back(i);
			mn = min(mn, b[i]);
			mx = max(mx, c[i]);
		}
		w.clear();
		int res = cum[M - 1];
		for (int i = mn; i <= mx; ++i) {
			for (size_t j = 0; j < s[i].size(); ++j)
				if (!vis[s[i][j]]) {
					w.push_back(s[i][j]);
					take[a[s[i][j]]] = in[s[i][j]] = true;
				}
			bool need = false;
			for (size_t j = 0; j < e[i].size() && !need; ++j)
				need |= in[e[i][j]];
			if (!need)
				continue;
			if (cum[i] - cum[i - 1] == 0 || take[i])
				++res;
			while (!w.empty()) {
				int v = w.back();
				w.pop_back();
				vis[v] = true;
				in[v] = take[a[v]] = false;
			}
		}
		printf("Case #%d: %d\n", cas++, res);
	}
	return 0;
}
