#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3;
int n, m, y, x[N];

inline int get(double v) {
	return v + 0.5;
}

bool comp(double a, double b) {
	return a == b || fabs(a - b) < 1e-5;
}

int main(int argc, char **argv) {
	scanf("%d%d%d", &n, &m, &y);
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	ll sum = 0;
	vector<pair<double, int> > a, b;
	for (int i = 0; i < n; ++i) {
		double v = (1.0 * x[i]) / y * m;
		int r1 = ceil(v);
		int r2 = get(v);
		x[i] = r1;
		sum += r1;
		if (comp(v, r1))
			continue;
		if (comp(r2, (int) v))
			b.push_back(make_pair(v - r2, i));
		else
			a.push_back(make_pair(r2 - v, i));
	}
	sum -= m;
	if (sum != 0) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (size_t i = 0; i < b.size() && sum; ++i, --sum)
			--x[b[i].second];
		while (!a.empty() && sum != 0) {
			--x[a.back().second];
			a.pop_back();
			--sum;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%s%d", i ? " " : "", x[i]);
	puts("");
	return 0;
}
