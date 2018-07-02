#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

inline string add(const string&x, const string&y) {
	int a = x.size(), b = y.size();
	int mn = min(a, b), mx = max(a, b), idx1 = a - 1, idx2 = b - 1, c = 0;
	string res = "";
	for (int i = 0; i < mn; ++i) {
		int d1 = x[idx1--] - '0', d2 = y[idx2--] - '0';
		res += (d1 + d2 + c) % 10 + '0';
		c = (d1 + d2 + c) / 10;
	}
	for (; mn < mx; ++mn) {
		int d = (a > b) ? (x[idx1--] - '0') : (y[idx2--] - '0');
		res += (d + c) % 10 + '0';
		c = (d + c) / 10;
	}
	if (c != 0)
		res += "1";
	reverse(res.begin(), res.end());
	return res;
}

int n, v[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[2010];

int main(int argc, char **argv) {
	for (int i = 1; i < 2001; ++i) {
		dp[i] = "0";
		for (int j = 1; j < 10; ++j)
			if (i - v[j] >= 0)
				dp[i] = add(dp[i], add(dp[i - v[j]], "1"));
		if (i - 6 >= 0)
			dp[i] = add(dp[i], dp[i - 6]);
	}
	while (scanf("%d", &n) > 0) {
		string res = "0";
		if (n >= 6)
			res = "1";
		cout << add(dp[n], res) << "\n";
	}
	return 0;
}
