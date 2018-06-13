#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, v[N][2], dp[N][2][2];

int calc(int at, bool a, bool b) {
	if (at == n)
		return 0;
	int &res = dp[at][a][b];
	if (res != -1)
		return res;
	res = calc(at + 1, true, true);
	if (a)
		res = max(res, calc(at + 1, false, true) + v[at][0]);
	if (b)
		res = max(res, calc(at + 1, true, false) + v[at][1]);
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i][0]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i][1]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, true, true));
	}
	return 0;
}
