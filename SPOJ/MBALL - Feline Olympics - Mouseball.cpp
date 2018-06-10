#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100001;
ll dp[N][5];
int back[] = { 2, 3, 6, 7, 8 };

int main(int argc, char **argv) {
	for (int i = 0; i < 5; ++i)
		dp[0][i] = 1;
	for (int j = 0; j < 5; ++j)
		for (int i = 1; i < N; ++i) {
			if (j > 0)
				dp[i][j] = dp[i][j - 1];
			if (i >= back[j])
				dp[i][j] += dp[i - back[j]][j];
		}
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n][4]);
	}
	return 0;
}
