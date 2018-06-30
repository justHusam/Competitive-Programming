#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int vis[10], vs;

int main(int argc, char **argv) {
	int n;
	bool f = false;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (f)
			puts("");
		f = true;
		vector<pair<int, int> > res;
		for (int i = 10000; i <= 100000; ++i)
			if (i % n == 0) {
				++vs;
				int t = i, f = 1;
				for (; t != 0 && f; t /= 10) {
					f &= vis[t % 10] != vs;
					vis[t % 10] = vs;
				}
				int b = i / n, c = 0;
				if (!f || (vis[0] == vs && b < 10000))
					continue;
				for (; b != 0 && f; b /= 10) {
					f &= vis[b % 10] != vs;
					vis[b % 10] = vs;
					++c;
				}
				if (!f || c < 4 || (c == 4 && vis[0] == vs))
					continue;
				res.push_back(make_pair(i / n, i));
			}
		if (!res.size())
			printf("There are no solutions for %d.\n", n);
		else {
			sort(res.begin(), res.end());
			for (size_t i = 0; i < res.size(); ++i)
				printf("%d / %s%d = %d\n", res[i].second, res[i].first < 10000 ? "0" : "", res[i].first, n);
		}
	}
	return 0;
}
