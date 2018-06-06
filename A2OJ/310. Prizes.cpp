#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6;
int n, w, a[N], b[N];
vector<int> v;

bool check(int m) {
	v.clear();
	for (int i = 0; i < n; ++i)
		v.push_back(a[i] + b[i] * (m - 1));
	sort(v.begin(), v.end());
	int k = 0;
	for (int i = 0; i < m; ++i) {
		k += v[i];
		if (k > w)
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &w);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		int l = 1, r = n, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m)) {
				res = m;
				l = m + 1;
			} else
				r = m - 1;
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
