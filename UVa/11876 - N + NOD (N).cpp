#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int calc(int n) {
	int res = 0;
	for (int i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			++res;
			if (i * i != n)
				++res;
		}
	return res;
}

int main(int argc, char **argv) {
	vector<int> all;
	int n = 1;
	do {
		all.push_back(n);
		n = n + calc(n);
	} while (n <= 1000000);
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		int aa = lower_bound(all.begin(), all.end(), a) - all.begin();
		int bb = lower_bound(all.begin(), all.end(), b) - all.begin();
		printf("Case %d: %d\n", k++, bb - aa + (all[bb] == b));
	}
	return 0;
}
