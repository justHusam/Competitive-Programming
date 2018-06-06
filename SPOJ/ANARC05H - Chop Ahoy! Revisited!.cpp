#include <bits/stdc++.h>
using namespace std;

string s;
int len, dp[27][27];

int sum(int start, int end) {
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += s[i] - '0';
	return sum;
}

int check(int start, int end) {
	int oldSum, sm = 0;
	if (end == len - 1)
		return 1;
	if (dp[start][end] != -1)
		return dp[start][end];
	oldSum = sum(start, end);
	for (int i = end + 1; i < len; i++)
		if (oldSum <= sum(end + 1, i))
			sm += check(end + 1, i);
	return dp[start][end] = sm;
}

int main(int argc, char **argv) {
	int T = 0;
	while (cin >> s && s != "bye") {
		int res = 0;
		len = s.length();
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < len; i++)
			res += check(0, i);
		printf("%d. %d\n", ++T, res);
	}
	return 0;
}
