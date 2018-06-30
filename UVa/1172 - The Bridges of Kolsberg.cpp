#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001;
int n, m;
char z[12];
map<string, int> hs;
pair<int, int> dp[N][N], a[N], b[N];

inline pair<int, int> max(pair<int, int> &a, pair<int, int> &b) {
	if (a.first > b.first || (a.first == b.first && a.second < b.second))
		return a;
	return b;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		hs.clear();
		scanf("%d", &n);
		int id = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%s", z);
			scanf("%s%d", z, &a[i].second);
			if (hs.find(z) == hs.end())
				hs[z] = id++;
			a[i].first = hs[z];
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%s", z);
			scanf("%s%d", z, &b[i].second);
			if (hs.find(z) == hs.end())
				hs[z] = id++;
			b[i].first = hs[z];
		}
		pair<int, int>res = make_pair(0, 0);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = make_pair(0, 0);
				if (a[i].first == b[j].first) {
					dp[i][j] = dp[i - 1][j - 1];
					dp[i][j].first += a[i].second + b[j].second;
					++dp[i][j].second;
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
				res = max(res, dp[i][j]);
			}
		printf("%d %d\n", res.first, res.second);
	}
	return 0;
}