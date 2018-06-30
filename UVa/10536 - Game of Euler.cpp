#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4, M = (1 << 16) - 1;
int dp[M][2], idx[N][N];
char g[N][N + 1];
vector<int> p[N][N];

int calc(int msk, int at) {
	if (msk == M)
		return at ^ 1;
	int &res = dp[msk][at];
	if (res != -1)
		return res;
	res = at ? 2e9 : 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (size_t k = 0; k < p[i][j].size(); ++k)
				if ((msk & p[i][j][k]) == 0) {
					if (at == 0)
						res = max(res, calc(msk | p[i][j][k], at ^ 1));
					else
						res = min(res, calc(msk | p[i][j][k], at ^ 1));
				}
	return res;
}

int main(int argc, char **argv) {
	int id = 15;
	for (int i = N - 1; i >= 0; --i)
		for (int j = N - 1; j >= 0; --j)
			idx[i][j] = id--;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			p[i][j].push_back(1 << idx[i][j]);
			if (i == 0) {
				p[i][j].push_back(p[i][j][0] | (1 << idx[i + 1][j]));
				p[i][j].push_back(p[i][j].back() | (1 << idx[i + 2][j]));
			}
			if (i == N - 1) {
				p[i][j].push_back(p[i][j][0] | (1 << idx[i - 1][j]));
				p[i][j].push_back(p[i][j].back() | (1 << idx[i - 2][j]));
			}
			if (j == 0) {
				p[i][j].push_back(p[i][j][0] | (1 << idx[i][j + 1]));
				p[i][j].push_back(p[i][j].back() | (1 << idx[i][j + 2]));
			}
			if (j == N - 1) {
				p[i][j].push_back(p[i][j][0] | (1 << idx[i][j - 1]));
				p[i][j].push_back(p[i][j].back() | (1 << idx[i][j - 2]));
			}
		}
	memset(dp, -1, sizeof dp);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 0; i < N; ++i)
			scanf("%s", g[i]);
		int msk = 0;
		for (int i = N - 1; i >= 0; --i)
			for (int j = N - 1; j >= 0; --j)
				msk = (msk << 1) | (g[i][j] == 'X');
		if (calc(msk, 0))
			puts("WINNING");
		else
			puts("LOSING");
	}
	return 0;
}
