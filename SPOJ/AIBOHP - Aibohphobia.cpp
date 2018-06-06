#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 6100;
char s[N];
int t, id;
short dp[N][N], vis[N][N];

int calc(int i, int j) {
	if (i >= j)
		return 0;
	if (vis[i][j] == id)
		return dp[i][j];
	vis[i][j] = id;
	if (s[i] == s[j])
		return dp[i][j] = calc(i + 1, j - 1);
	int r1 = calc(i + 1, j) + 1;
	int r2 = calc(i, j - 1) + 1;
	return dp[i][j] = min(r1, r2);
}

int main(int argc, char **argv) {
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		++id;
		printf("%d\n", calc(0, strlen(s) - 1));
	}
	return 0;
}
