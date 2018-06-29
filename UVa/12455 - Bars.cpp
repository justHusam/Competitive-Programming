#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int len, n, dp[1001][20], v[20];

int calc(int w, int i) {
	if (w == len)
		return 1;
	if (w > len || i == n)
		return 0;
	int &res = dp[w][i];
	if (res != -1)
		return res;
	return res = max(calc(w + v[i], i + 1), calc(w, i + 1));
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &len, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		memset(dp, -1, sizeof dp);
		if (calc(0, 0) != 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
