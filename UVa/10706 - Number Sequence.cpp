#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int v[33001];
vector<ll> cum;

inline int get(int n) {
	int res = 0;
	for (; n; n /= 10)
		++res;
	return res;
}

int calc(int n) {
	int w = 0;
	for (int i = 1;; ++i) {
		if (w + v[i] < n)
			w += v[i];
		else {
			int x = w + v[i] - n;
			for (; x; --x)
				i /= 10;
			return i % 10;
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	cum.push_back(0);
	for (int i = 1; i < 33000; ++i)
		v[i] = get(i);
	ll lst = 0;
	for (int i = 1; i < 33000; ++i) {
		lst += v[i];
		cum.push_back(cum.back() + lst);
	}
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		int i = lower_bound(cum.begin(), cum.end(), n) - cum.begin();
		printf("%d\n", calc(n - cum[i - 1]));
	}
	return 0;
}