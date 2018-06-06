#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2000;
int n, m;
short dp[N][N];
char a[N + 1], b[N + 1];
vector<vector<int> > g;
vector<bool> E;
vector<int> node(26, -1);

void insert(int s, int e) {
	int cur = 0;
	for (int i = s; i <= e; ++i) {
		if (g[cur][a[i] - 'a'] == -1) {
			g[cur][a[i] - 'a'] = g.size();
			g.push_back(node);
			E.push_back(false);
		}
		cur = g[cur][a[i] - 'a'];
	}
	E[cur] = true;
}

short check(int i, int j) {
	if (i >= j)
		return dp[i][j] = 1;
	short &res = dp[i][j];
	if (res != -1)
		return res;
	res = 0;
	if (a[i] == a[j])
		res = check(i + 1, j - 1);
	return res;
}

pair<int, int> go(int s) {
	int cur = 0;
	pair<int, int> res = make_pair(-1, -1);
	for (int i = s; i < m; ++i) {
		if (g[cur][b[i] - 'a'] == -1)
			break;
		cur = g[cur][b[i] - 'a'];
		if (E[cur])
			res = make_pair(s, i);
	}
	return res;
}

int main(int argc, char **argv) {
	scanf("%s%s", a, b);
	n = strlen(a);
	m = strlen(b);
	g.push_back(node);
	E.push_back(false);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; ++i) {
		int e = i;
		for (int j = i; j < n; ++j) {
			check(i, j);
			if (dp[i][j] == 1)
				e = j;
		}
		insert(i, e);
	}
	int x = -1, y = -1, mx = 0;
	for (int i = 0; i < m; ++i) {
		pair<int, int> v = go(i);
		if (v.first == -1)
			continue;
		int len = v.second - v.first + 1;
		if (len > mx) {
			mx = len;
			x = v.first;
			y = v.second;
		}
	}
	for (int i = x; i <= y; ++i)
		printf("%c", b[i]);
	puts("");
	return 0;
}
