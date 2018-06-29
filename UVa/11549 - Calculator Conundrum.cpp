#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int calc(ll n) {
	int cnt = 0;
	for (; n; n /= 10)
		++cnt;
	return cnt;
}

int main(int argc, char **argv) {
	int t;
	cin >> t;
	while (t-- != 0) {
		ll n, k;
		cin >> n >> k;
		ll res = k;
		map<ll, bool> vis;
		while (!vis[k]) {
			vis[k] = true;
			ll P = k * k;
			int cnt = calc(P);
			if (cnt > n)
				while (cnt != n)
					P /= 10, --cnt;
			k = P;
			res = max(res, k);
		}
		cout << res << "\n";
	}
	return 0;
}
