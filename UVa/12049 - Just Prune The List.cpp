#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int n, m, a[N], b[N], freq[N][2];
vector<int> hs;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 0; i < N; ++i)
			freq[i][0] = freq[i][1] = 0;
		scanf("%d%d", &n, &m);
		hs.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			hs.push_back(a[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &b[i]);
			hs.push_back(b[i]);
		}
		sort(hs.begin(), hs.end());
		hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
		for (int i = 0; i < n; ++i) {
			a[i] = lower_bound(hs.begin(), hs.end(), a[i]) - hs.begin();
			++freq[a[i]][0];
		}
		for (int i = 0; i < m; ++i) {
			b[i] = lower_bound(hs.begin(), hs.end(), b[i]) - hs.begin();
			++freq[b[i]][1];
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
			res += abs(freq[i][0] - freq[i][1]);
		printf("%d\n", res);
	}
	return 0;
}
