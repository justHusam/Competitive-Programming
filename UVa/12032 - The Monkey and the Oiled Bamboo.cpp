#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, v[100000];

bool check(int k) {
	if (v[0] > k)
		return false;
	k -= v[0] == k;
	for (int i = 1; i < n; ++i) {
		if (v[i] - v[i - 1] > k)
			return false;
		k -= v[i] - v[i - 1] == k;
	}
	return true;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		int l = 0, r = 1e9, res;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (check(m))
				res = m, r = m - 1;
			else
				l = m + 1;
		}
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}