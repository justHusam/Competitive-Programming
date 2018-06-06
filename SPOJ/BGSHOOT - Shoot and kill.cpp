#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100001;
int n, q, s[N], e[N], l[N], r[N], cum[N << 2], dp[N << 2][19];
vector<int> hs;

inline int calc(int l, int r) {
	int log = 0;
	while ((1 << log) <= r - l + 1)
		++log;
	--log;
	return max(dp[l][log], dp[r - (1 << log) + 1][log]);
}

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &s[i], &e[i]);
		hs.push_back(s[i]);
		hs.push_back(e[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		hs.push_back(l[i]);
		hs.push_back(r[i]);
	}
	sort(hs.begin(), hs.end());
	hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
	for (int i = 0; i < n; ++i) {
		s[i] = lower_bound(hs.begin(), hs.end(), s[i]) - hs.begin();
		e[i] = lower_bound(hs.begin(), hs.end(), e[i]) - hs.begin();
		++cum[s[i]];
		--cum[e[i] + 1];
	}
	int sz = hs.size(), add = 0;
	for (int i = 0; i < sz; ++i) {
		add += cum[i];
		dp[i][0] = add;
	}
	for (int j = 1; (1 << j) < sz; ++j)
		for (int i = 0; i < sz; ++i)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	for (int i = 0; i < q; ++i) {
		l[i] = lower_bound(hs.begin(), hs.end(), l[i]) - hs.begin();
		r[i] = lower_bound(hs.begin(), hs.end(), r[i]) - hs.begin();
		printf("%d\n", calc(l[i], r[i]));
	}
	return 0;
}
