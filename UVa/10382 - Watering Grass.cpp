#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<double, double> > v;
int n, l, w;

int main(int argc, char **argv) {
	while (scanf("%d%d%d", &n, &l, &w) != EOF) {
		v.clear();
		for (int i = 0; i < n; ++i) {
			int x, r;
			scanf("%d%d", &x, &r);
			if (r * 2 >= w) {
				double dx = max(0.0, 1.0 * r * r - (w / 2.0) * (w / 2.0));
				dx = sqrt(dx);
				v.push_back(make_pair(x - dx, x + dx));
			}
		}
		sort(v.begin(), v.end());
		int need = -1;
		double at = 0;
		for (size_t i = 0; i < v.size(); ++i) {
			int take = -1;
			while (i < v.size() && v[i].first <= at) {
				if (take == -1 || v[i].second >= v[take].second)
					take = i;
				++i;
			}
			if (take == -1) {
				need = -1;
				break;
			}
			if (need == -1)
				need = 0;
			++need;
			i = take;
			at = v[take].second;
			if (at >= l)
				break;
		}
		if (at < l)
			need = -1;
		printf("%d\n", need);
	}
	return 0;
}
