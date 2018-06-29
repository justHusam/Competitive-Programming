#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
int n, dp[N], d[N];

int main(int argc, char **argv) {
	for (int i = 1; i < N; ++i)
		for (int j = i; j < N; j += i)
			++d[j];
	dp[1] = 1;
	for (int i = 1; i < N; ++i)
		if (d[i] >= d[dp[i - 1]])
			dp[i] = i;
		else
			dp[i] = dp[i - 1];
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}
