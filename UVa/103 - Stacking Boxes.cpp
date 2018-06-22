#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m, g[N][N], dp[N];
vector<int> p;

bool check(const vector<int>&v, const vector<int>&vv) {
	for (size_t i = 0; i < v.size(); ++i)
		if (v[i] >= vv[i])
			return false;
	return true;
}

int calc(int i) {
	if (dp[i] != -1)
		return dp[i];
	int res = 0;
	for (int j = 0; j < n; ++j)
		if (g[i][j])
			res = max(res, calc(j) + 1);
	return dp[i] = res;
}

void path(int i) {
	int res = -1, str = -1;
	for (int j = 0; j < n; ++j) {
		if (!g[i][j])
			continue;
		int temp = calc(j);
		if (temp > res) {
			res = temp;
			str = j;
		}
	}
	p.push_back(i + 1);
	if (str != -1)
		path(str);
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		vector<vector<int> > v;
		for (int i = 0; i < n; ++i) {
			vector<int> vv(m);
			for (int j = 0; j < m; ++j)
				scanf("%d", &vv[j]);
			sort(vv.begin(), vv.end());
			v.push_back(vv);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = check(v[i], v[j]);
		memset(dp, -1, sizeof dp);
		int res = 0, str;
		for (int i = 0; i < n; ++i) {
			int temp = calc(i) + 1;
			if (temp > res) {
				res = temp;
				str = i;
			}
		}
		printf("%d\n", res);
		p.clear();
		path(str);
		string s = "";
		for (int i = 0; i < (int) p.size(); ++i) {
			printf("%s%d", s.c_str(), p[i]);
			s = " ";
		}
		puts("");
	}
	return 0;
}
