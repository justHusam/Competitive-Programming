#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 1;
int co[N], dp[N], cum[N];

int calc(int n) {
	if (n == 1)
		return 0;
	if (dp[n] == -1)
		dp[n] = calc(co[n]) + 1;
	return dp[n];
}

int main(int argc, char **argv) {
	for (int i = 2; i < N; ++i)
		co[i] = i, dp[i] = -1;
	for (int i = 2; i < N; ++i)
		if (co[i] == i)
			for (int j = i; j < N; j += i)
				co[j] -= co[j] / i;
	for (int i = 2; i < N; ++i)
		cum[i] = cum[i - 1] + calc(i);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", cum[b] - cum[a - 1]);
	}
	return 0;
}