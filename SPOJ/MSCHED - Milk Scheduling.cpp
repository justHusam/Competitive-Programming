#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e4 + 9;
vector<int> g[N];
int mx, res, n;
priority_queue<int> qu;

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[y].push_back(x);
		mx = max(mx, y);
	}
	for (int i = mx; i > 0; --i) {
		for (size_t j = 0; j < g[i].size(); ++j)
			qu.push(g[i][j]);
		if (!qu.empty()) {
			res += qu.top();
			qu.pop();
		}
	}
	printf("%d\n", res);
	return 0;
}
