#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n, k;
vector<int> X, id;
vector<vector<int> > g;

int calc(int idx) {
	queue<int> qu;
	bitset<5010> vis;
	vis.reset();
	qu.push(idx);
	vis[idx] = 0;
	int res = 1;
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		++res;
		for (size_t i = 0; i < g[u].size(); ++i)
			if (!vis[g[u][i]]) {
				vis[g[u][i]] = 1;
				qu.push(g[u][i]);
			}
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &k) > 0) {
		X.clear();
		X.resize(k);
		id.clear();
		id.resize(n);
		for (int i = 0; i < k; ++i)
			scanf("%d", &X[i]);
		cin.ignore();
		g.clear();
		g.resize(n);
		for (int i = 0; i < n; ++i) {
			string s;
			getline(cin, s);
			stringstream ss(s);
			vector<int> v;
			int x;
			while (ss >> x)
				v.push_back(x);
			id[i] = v[0];
			--id[i];
			for (size_t j = 1; j < v.size(); ++j)
				g[i].push_back(v[j] - 1);
		}
		int res = -1, mn = 0;
		sort(X.begin(), X.end());
		for (int i = 0; i < k; ++i) {
			int temp = calc(X[i] - 1);
			if (temp > mn)
				mn = temp, res = X[i];
		}
		printf("%d\n", res);
	}
	return 0;
}
