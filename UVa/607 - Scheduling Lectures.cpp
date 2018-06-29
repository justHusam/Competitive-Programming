#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 1e3 + 1, L = 501;
int n, l, c, v[N], dp1[N][L], dp2[N][L];

int calc1(int idx, int sum) {
	if (sum > l)
		return 2e9;
	if (idx == n)
		return 1;
	if (dp1[idx][sum] != -1)
		return dp1[idx][sum];
	int a = calc1(idx + 1, sum + v[idx]);
	int b = calc1(idx + 1, v[idx]) + 1;
	return dp1[idx][sum] = min(a, b);
}

inline int get(int n) {
	if (n == 0)
		return 0;
	if (n <= 10)
		return -c;
	return (n - 10) * (n - 10);
}

int calc2(int idx, int sum) {
	if (sum > l)
		return 2e9;
	if (idx == n)
		return get(l - sum);
	if (dp2[idx][sum] != -1)
		return dp2[idx][sum];
	int a = calc1(idx + 1, sum + v[idx]);
	int b = calc1(idx + 1, v[idx]) + 1;
	if (a < b)
		return dp2[idx][sum] = calc2(idx + 1, sum + v[idx]);
	if (b < a)
		return dp2[idx][sum] = calc2(idx + 1, v[idx]) + get(l - sum);
	int x = calc2(idx + 1, sum + v[idx]);
	int y = calc2(idx + 1, v[idx]) + get(l - sum);
	return dp2[idx][sum] = min(x, y);
}

int main(int argc, char **argv) {
	int caseN = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (caseN != 1)
			puts("");
		scanf("%d%d", &l, &c);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		memset(dp1, -1, sizeof dp1);
		memset(dp2, -1, sizeof dp2);
		printf("Case %d:\n", caseN++);
		printf("Minimum number of lectures: %d\n", calc1(1, v[0]));
		printf("Total dissatisfaction index: %d\n", calc2(1, v[0]));
	}
	return 0;
}
