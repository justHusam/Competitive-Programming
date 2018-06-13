#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int g[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { -1, 0, -1 } };
vector<int> v;

void DFS(int x, int y, int with) {
	v.push_back(with);
	if (x == 4 || y == 3 || g[x][y] == -1 || with > 200)
		return;
	if (with != 0 || g[x][y] != 0)
		DFS(x, y, with * 10 + g[x][y]);
	DFS(x + 1, y, with);
	DFS(x, y + 1, with);
}

int main(int argc, char **argv) {
	DFS(0, 0, 0);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		int k = lower_bound(v.begin(), v.end(), n) - v.begin();
		int diff = 2e9, at = -1;
		for (int i = -1; i < 2; ++i) {
			if (k + i < 0 || k + i >= (int) v.size())
				continue;
			int x = v[k + i];
			if (abs(n - x) <= diff) {
				diff = abs(n - x);
				at = x;
			}
		}
		printf("%d\n", at);
	}
	return 0;
}
