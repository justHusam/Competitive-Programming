#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int n, sum, v[40];
map<int, bool> dp[40];
map<int, string> arr[40];

int calc(int i, int s) {
	if (i == n)
		return s == sum;
	if (dp[i].find(s) != dp[i].end())
		return dp[i][s];
	return dp[i][s] = calc(i + 1, s + v[i]) + calc(i + 1, s - v[i]);
}

string path(int i, int s) {
	if (i == n)
		return "";
	if (arr[i].find(s) != arr[i].end())
		return arr[i][s];
	int a = calc(i + 1, s + v[i]);
	int b = calc(i + 1, s - v[i]);
	if (a != 0 && b != 0) {
		string x = '+' + path(i + 1, s + v[i]);
		string y = '-' + path(i + 1, s - v[i]);
		for (int a = 0; a < x.size(); ++a)
			if (x[a] != y[a])
				x[a] = '?';
		return arr[i][s] = x;
	}
	if (a != 0)
		return arr[i][s] = '+' + path(i + 1, s + v[i]);
	return arr[i][s] = '-' + path(i + 1, s - v[i]);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &sum) > 0 && n != 0) {
		int all = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", v + i);
			all += v[i];
			dp[i].clear();
			arr[i].clear();
		}
		if (sum > all || -all > sum || calc(0, 0) == 0) {
			puts("*");
			continue;
		}
		puts(path(0, 0).c_str());
	}
	return 0;
}
