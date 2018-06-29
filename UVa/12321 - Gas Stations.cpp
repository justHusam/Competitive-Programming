#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int> > v;
int n, L;

int main(int argc, char **argv) {
	while (scanf("%d%d", &L, &n) > 0 && (n != 0 || L != 0)) {
		v.clear();
		for (int i = 0; i < n; ++i) {
			int x, r;
			scanf("%d%d", &x, &r);
			v.push_back(make_pair(x - r, x + r));
		}
		sort(v.begin(), v.end());
		int need = 0, at = 0;
		for (int i = 0; i < n; ++i) {
			int take = -1;
			while (i < n && v[i].first <= at) {
				if (take == -1 || v[i].second >= v[take].second)
					take = i;
				++i;
			}
			if (take == -1) {
				need = -1;
				break;
			}
			++need;
			at = v[take].second;
			i = take;
			if (at >= L)
				break;
		}
		if (at < L || need == -1)
			puts("-1");
		else
			printf("%d\n", n - need);
	}
	return 0;
}
