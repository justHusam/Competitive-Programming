#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4001;
int n, dp[N], ok[N][N];
char s[N];
bool E[N];

int check(int l, int r) {
	if (l >= r)
		return 1;
	int &res = ok[l][r];
	if (res != -1)
		return res;
	res = 0;
	if (s[l] == s[r])
		res = check(l + 1, r - 1);
	return res;
}

int calc(int at) {
	if (at == n)
		return 0;
	int &res = dp[at];
	if (res != -1)
		return res;
	res = 2e9;
	for (int i = at; i < n; ++i)
		if (check(at, i))
			res = min(res, calc(i + 1) + 1);
	return res;
}

void path(int at) {
	if (at == n)
		return;
	for (int i = at; i < n; ++i)
		if (check(at, i) && calc(i + 1) + 1 == calc(at)) {
			E[i + 1] = true;
			path(i + 1);
			break;
		}
}

int main(int argc, char **argv) {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		dp[i] = -1;
		for (int j = i; j < n; ++j)
			ok[i][j] = ok[j][i] = -1;
	}
	printf("%d\n", calc(0));
	path(0);
	for (int i = 0; i < n; ++i) {
		if (E[i])
			printf(" ");
		printf("%c", s[i]);
	}
	puts("");
	return 0;
}
