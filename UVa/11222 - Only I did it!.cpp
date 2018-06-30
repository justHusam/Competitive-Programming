#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool vis[3][10001];
vector<int> v[3];

vector<int> calc(int a, int b, int c) {
	vector<int> res;
	for (size_t i = 0; i < v[a].size(); ++i)
		if (!vis[b][v[a][i]] && !vis[c][v[a][i]])
			res.push_back(v[a][i]);
	return res;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		memset(vis, false, sizeof vis);
		for (int i = 0, x; i < 3; ++i) {
			scanf("%d", &x);
			v[i] = vector<int>(x);
			for (int j = 0; j < x; ++j)
				scanf("%d", &v[i][j]), vis[i][v[i][j]] = true;
		}
		vector<int> res[3] = { calc(0, 1, 2), calc(1, 0, 2), calc(2, 0, 1) };
		int mx = max(res[0].size(), max(res[1].size(), res[2].size()));
		printf("Case #%d:\n", k++);
		for (int i = 0; i < 3; ++i)
			if ((int) res[i].size() == mx) {
				printf("%d %d", i + 1, (int) res[i].size());
				sort(res[i].begin(), res[i].end());
				for (size_t j = 0; j < res[i].size(); ++j)
					printf(" %d", res[i][j]);
				puts("");
			}
	}
	return 0;
}
