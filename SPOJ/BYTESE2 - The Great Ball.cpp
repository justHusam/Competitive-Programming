#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x[100], y[100], s[200], e[200];
vector<int> hs;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		hs.clear();
		for (int i = 0; i < 200; ++i)
			s[i] = e[i] = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			hs.push_back(x[i]);
			hs.push_back(y[i]);
		}
		sort(hs.begin(), hs.end());
		hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
		for (int i = 0; i < n; ++i) {
			x[i] = lower_bound(hs.begin(), hs.end(), x[i]) - hs.begin();
			y[i] = lower_bound(hs.begin(), hs.end(), y[i]) - hs.begin();
			++s[x[i]];
			++e[y[i]];
		}
		int at = 0, mx = 0;
		for (size_t i = 0; i < hs.size(); ++i) {
			at += s[i];
			mx = max(mx, at);
			at -= e[i];
		}
		printf("%d\n", mx);
	}
	return 0;
}
