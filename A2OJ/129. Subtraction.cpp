#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int dp[150][150][2];
vector<int> v;
string s;

int calc(int s, int e, int f) {
	if (e - s == 1)
		return v[s] - v[e];
	if (s == e)
		return v[s];
	if (dp[s][e][f] != -1)
		return dp[s][e][f];
	int res = 2e9;
	if (f)
		res = INT_MIN;
	for (int a = s; a < e; ++a) {
		int l1 = calc(s, a, 1);
		int l2 = calc(s, a, 0);
		int r1 = calc(a + 1, e, 0);
		int r2 = calc(a + 1, e, 1);
		if (f) {
			res = max(res, l1 - r1);
			res = max(res, l1 - r2);
			res = max(res, l2 - r1);
			res = max(res, l2 - r2);
			continue;
		}
		res = min(res, l1 - r1);
		res = min(res, l1 - r2);
		res = min(res, l2 - r1);
		res = min(res, l2 - r2);
	}
	return dp[s][e][f] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d\n", &T);
	while (T-- != 0) {
		getline(cin, s);
		stringstream ss(s);
		int x;
		v.clear();
		while (ss >> x)
			v.push_back(x);
		int n = v.size();
		memset(dp, -1, sizeof dp);
		printf("%d\n", max(calc(0, n - 1, 0), calc(0, n - 1, 1)));
	}
	return 0;
}
