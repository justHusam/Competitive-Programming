#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3;

int main(int argc, char **argv) {
	int dp[1010] = { };
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= N + 1; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % N;
	vector<int> g[1010];
	for (int i = 0; i <= N; ++i)
		g[dp[i]].push_back(i);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		if (!g[n].size()) {
			puts("These digits seem to be invalid");
			continue;
		}
		string p = " ";
		printf("The last three digits of");
		for (size_t i = 0; i < g[n].size(); ++i, p = ", ")
			printf("%sF(%d)", p.c_str(), g[n][i]);
		printf(" are [%d]\n", n);
	}
	return 0;
}
