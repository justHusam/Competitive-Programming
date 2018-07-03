#include <bits/stdc++.h>
using namespace std;

struct state {
	int w, q, i;
	state(int w, int q, int i) :
			w(w), q(q), i(i) {
	}
	bool operator<(const state&e) const {
		return q > e.q;
	}
};

vector<state> v;
const int N = 1e3 + 2;
int n, dp[N][N];
vector<int> res;

int calc(int i, int p) {
	if (i == n - 1)
		return 0;
	if (dp[i][p] != -1)
		return dp[i][p];
	int a = calc(i + 1, p), b = 0;
	if (v[i].w > v[p].w && v[i].q < v[p].q)
		b = calc(i + 1, i) + 1;
	return dp[i][p] = max(a, b);
}

void path(int i, int p) {
	if (i == n - 1)
		return;
	int a = calc(i + 1, p), b = -1;
	if (v[i].w > v[p].w && v[i].q < v[p].q)
		b = calc(i + 1, i) + 1;
	if (a > b) {
		path(i + 1, p);
		return;
	}
	res.push_back(v[i].i);
	path(i + 1, i);
}

int main(int argc, char **argv) {
	int x, y, k = 1;
	while (scanf("%d%d", &x, &y) > 0)
		v.push_back(state(x, y, k++));
	sort(v.begin(), v.end());
	v.push_back(state(-1, 2e9, -1));
	n = v.size();
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(0, n - 1));
	path(0, n - 1);
	for (size_t i = 0; i < res.size(); ++i)
		printf("%d\n", res[i]);
	return 0;
}
