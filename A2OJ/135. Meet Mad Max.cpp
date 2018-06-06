#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, m;
		scanf("%d%d", &m, &n);
		vector<ll> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &v[i]);
		sort(v.begin(), v.end());
		pair<ll, ll> res;
		ll val = -1;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				if (v[i] == v[j])
					continue;
				ll temp = (v[i] * v[j]) % m;
				if ((temp > val) || (temp == val && v[i] < res.first) || (temp == val && v[i] == res.first && v[j] < res.second)) {
					val = temp;
					res.first = v[i], res.second = v[j];
				}
			}
		printf("%lld %lld\n", res.first, res.second);
	}
	return 0;
}
