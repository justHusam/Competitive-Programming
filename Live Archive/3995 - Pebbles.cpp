#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 15;
struct state {
	bitset<N> bs;
	state(bitset<N> bs) :
			bs(bs) {
	}
};
int n, m, dp[1 << N][N], dx[] = { 1, -1, 0 };
vector<vector<int> > g;
vector<state> pre[1 << 16][N];

bool check(const bitset<N>&oldMask, const bitset<N>&newMask) {
	for (int i = 0; i < n; ++i)
		if (newMask[i]) {
			for (int j = 0; j < 3; ++j)
				if (i + dx[j] >= 0 && i + dx[j] < n && oldMask[i + dx[j]] == 1)
					return false;
			if (i - 1 >= 0 && newMask[i - 1] == 1)
				return false;
			if (i + 1 < n && newMask[i + 1] == 1)
				return false;
		}
	return true;
}

int calc(const bitset<N>&mask, int at) {
	if (at == n)
		return 0;
	int &res = dp[mask.to_ulong()][at];
	if (res != -1)
		return res;
	res = 0;
	int A = mask.to_ulong();
	if (pre[A][n].size()) {
		for (size_t i = 0; i < pre[A][n].size(); ++i) {
			int r = 0;
			for (int j = 0; j < n; ++j)
				if (pre[A][n][i].bs[j] == 1)
					r += g[at][j];
			res = max(res, calc(pre[A][n][i].bs, at + 1) + r);
		}
		return res;
	}
	vector<state> v;
	for (int i = 0; i < m; ++i) {
		bitset<N> newMask = i;
		if (!check(mask, newMask))
			continue;
		v.push_back(newMask);
		int r = 0;
		for (int j = 0; j < n; ++j)
			if (newMask[j] == 1)
				r += g[at][j];
		res = max(res, calc(newMask, at + 1) + r);
	}
	pre[A][n] = v;
	return res;
}

int main(int argc, char **argv) {
	string s;
	while (getline(cin, s)) {
		g.clear();
		do {
			vector<int> v;
			int x;
			stringstream ss(s);
			while (ss >> x)
				v.push_back(x);
			g.push_back(v);
		} while (getline(cin, s) && s.size());
		n = g.size();
		m = (1 << n);
		memset(dp, -1, sizeof dp);
		printf("%d\n", calc(0, 0));
	}
	return 0;
}
