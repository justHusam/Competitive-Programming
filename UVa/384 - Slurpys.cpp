#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 60;
char z[N + 1];
string s;
map<string, bool> hs[2];
int n, dp[N][2];

int slump(int i, int j) {
	string temp = s.substr(i, j - i + 1);
	int n = temp.length();
	if (hs[0].find(temp) != hs[0].end())
		return hs[0][temp];
	if (temp[0] != 'D' && temp[0] != 'E')
		return hs[0][temp] = 0;
	if (n < 3)
		return hs[0][temp] = 0;
	int pos = -1;
	for (int a = 2; a < n; ++a)
		if (temp[a] != 'F') {
			pos = a;
			break;
		}
	if (pos == -1)
		return hs[0][temp] = 0;
	if (pos == n - 1 && temp[pos] == 'G')
		return hs[0][temp] = 1;
	if (slump(i + pos, j))
		return hs[0][temp] = 1;
	return hs[0][temp] = 0;
}

int slimp(int i, int j) {
	string temp = s.substr(i, j - i + 1);
	int n = temp.length();
	if (hs[1].find(temp) != hs[1].end())
		return hs[1][temp];
	if (temp[0] != 'A')
		return hs[1][temp] = 0;
	if (n == 2)
		return hs[1][temp] = temp[1] == 'H';
	if (n == 3)
		return hs[1][temp] = 0;
	if (temp[1] == 'B' && temp[n - 1] == 'C' && slimp(i + 2, j - 1))
		return hs[1][temp] = 1;
	if (temp[n - 1] == 'C' && slump(i + 1, j - 1))
		return hs[1][temp] = 1;
	return hs[1][temp] = 0;
}

int calc(int i, int f) {
	if (i == n)
		return 1;
	if (dp[i][f] != -1)
		return dp[i][f];
	int res = 0;
	if (f) {
		for (int a = 1; a + i <= n; ++a)
			if (slump(i, i + a - 1))
				res = res | calc(i + a, 0);
		return dp[i][f] = res;
	}
	for (int a = 1; a + i <= n; ++a)
		if (slimp(i, i + a - 1))
			res = res | calc(i + a, 1);
	return dp[i][f] = res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	puts("SLURPYS OUTPUT");
	while (T-- != 0) {
		scanf("%s", z);
		s = z;
		memset(dp, -1, sizeof dp);
		n = s.length();
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		if (calc(0, 0) != 0)
			puts("YES");
		else
			puts("NO");
	}
	puts("END OF OUTPUT");
	return 0;
}
