#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n, need, par[N], freq[N], ch[N], at[N];
bool vis[N];

bool check(int v) {
	double p = 1.0 * freq[v] / ch[v] * 100;
	return p >= need || fabs(p - need) < 1e-6;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &need) && (n != 0 || need != 0)) {
		for (int i = 0; i <= n; ++i) {
			at[i] = ch[i] = freq[i] = 0;
			vis[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &par[i]);
			++ch[par[i]];
		}
		priority_queue<pair<int, int> > qu;
		for (int i = 1; i <= n; ++i)
			if (ch[i] == 0)
				qu.push(make_pair(-1, i));
		int res = 0;
		while (true) {
			pair<int, int> e = qu.top();
			qu.pop();
			e.first *= -1;
			if (e.second == 0) {
				res = e.first;
				break;
			}
			int p = par[e.second];
			if (vis[p])
				continue;
			++freq[p];
			at[p] += e.first;
			if (check(p)) {
				vis[p] = true;
				qu.push(make_pair(-at[p], p));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
