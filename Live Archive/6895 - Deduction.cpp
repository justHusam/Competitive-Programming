#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1501;
int n, m1, m2, m3, st[N], E[N], a[N];
vector<int> x[N], y[N];
bool vis[N];

bool check() {
	bool need = true;
	while (need) {
		need = false;
		for (int i = 0; i < m1; ++i)
			if (st[a[i]] != 1)
				return false;
		for (int i = 0; i < m2; ++i) {
			int c = 0;
			for (size_t j = 0; j < x[i].size(); ++j)
				c += st[x[i][j]] == 1;
			if (c == (int) x[i].size())
				return false;
			if (c + 1 == (int) x[i].size() && !vis[i]) {
				for (size_t j = 0; j < x[i].size(); ++j)
					if (st[x[i][j]] == -1) {
						st[x[i][j]] = 0;
						need = true;
						break;
					}
				vis[i] = true;
			}
		}
		for (int i = 0; i < m3; ++i) {
			bool all = true;
			for (size_t j = 0; j < y[i].size(); ++j)
				all &= st[y[i][j]] == 1;
			if (all && st[E[i]] == 0)
				return false;
			if (all && st[E[i]] != 1) {
				st[E[i]] = 1;
				need = true;
			}
		}
	}
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d%d", &n, &m1, &m2, &m3);
		for (int i = 0; i < N; ++i) {
			st[i] = -1;
			x[i].clear();
			y[i].clear();
			vis[i] = false;
		}
		for (int i = 0; i < m1; ++i) {
			scanf("%d", &a[i]);
			st[a[i]] = 1;
		}
		for (int i = 0, k; i < m2; ++i) {
			scanf("%d", &k);
			x[i].resize(k);
			for (int j = 0; j < k; ++j)
				scanf("%d", &x[i][j]);
		}
		for (int i = 0, k; i < m3; ++i) {
			scanf("%d", &k);
			y[i].resize(k);
			for (int j = 0; j < k; ++j)
				scanf("%d", &y[i][j]);
			scanf("%d", &E[i]);
		}
		if (check())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
