#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, v[14];
ll res;

inline void calc(int at, bitset<14> msk) {
	if (at == n) {
		vector<int> x, y;
		int Z[2] = { };
		for (int i = 0; i < n; ++i) {
			if (!v[i])
				++Z[!msk[i]];
			else if (msk[i])
				x.push_back(v[i]);
			else
				y.push_back(v[i]);
		}
		if (x.empty() || y.empty())
			return;
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		ll num1 = x[0], num2 = y[0];
		while (Z[0]-- != 0)
			num1 *= 10;
		while (Z[1]-- != 0)
			num2 *= 10;
		for (size_t i = 1; i < x.size(); ++i)
			num1 = num1 * 10 + x[i];
		for (size_t i = 1; i < y.size(); ++i)
			num2 = num2 * 10 + y[i];
		res = min(res, num1 + num2);
		return;
	}
	calc(at + 1, msk);
	msk[at] = 1;
	calc(at + 1, msk);
	msk[at] = 0;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		res = 1e18;
		calc(0, 0);
		cout << res << "\n";
	}
	return 0;
}
