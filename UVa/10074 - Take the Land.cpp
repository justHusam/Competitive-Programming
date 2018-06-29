#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000;
int n, m, nxt[N][N], l[N], r[N];
char g[N][N];
vector<int> v, st;

int calc(int R) {
	v.clear();
	for (int j = 0; j < m; ++j)
		if (g[R][j] == '0')
			v.push_back(nxt[R][j] - R);
		else
			v.push_back(0);
	st.clear();
	for (int i = 0; i < m; ++i) {
		while (!st.empty() && v[st.back()] >= v[i])
			st.pop_back();
		if (st.empty())
			l[i] = -1;
		else
			l[i] = st.back();
		st.push_back(i);
	}
	st.clear();
	for (int i = m - 1; i >= 0; --i) {
		while (!st.empty() && v[st.back()] >= v[i])
			st.pop_back();
		if (st.empty())
			r[i] = m;
		else
			r[i] = st.back();
		st.push_back(i);
	}
	int res = 0;
	for (int i = 0; i < m; ++i)
		res = max(res, v[i] * (r[i] - l[i] - 1));
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m > 0) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf(" %c", &g[i][j]);
		for (int j = 0; j < m; ++j) {
			int at = n;
			for (int i = n - 1; i >= 0; --i) {
				nxt[i][j] = at;
				if (g[i][j] == '1')
					at = i;
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
			res = max(res, calc(i));
		printf("%d\n", res);
	}
	return 0;
}
