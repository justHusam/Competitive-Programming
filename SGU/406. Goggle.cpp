#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int> > g;
vector<int> v;
vector<set<int> > st;
set<int>::iterator it;

bool check(set<int>&st, vector<int>&v) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] < 0) {
			if (st.find(-v[i]) != st.end())
				return false;
		} else {
			if (st.find(v[i]) == st.end())
				return false;
		}
	}
	return true;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	g.resize(n);
	st.resize(n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		g[i].resize(x);
		for (int j = 0; j < x; ++j)
			scanf("%d", &g[i][j]);
		st[i].insert(g[i].begin(), g[i].end());
	}
	while (m-- != 0) {
		int k;
		scanf("%d", &k);
		v.clear();
		v.resize(k);
		for (int i = 0; i < k; ++i)
			scanf("%d", &v[i]);
		vector<int> ok;
		for (int i = 0; i < n; ++i)
			if (check(st[i], v))
				ok.push_back(i);
		printf("%d\n", (int) ok.size());
		for (size_t i = 0; i < ok.size(); ++i) {
			printf("%d", (int) g[ok[i]].size());
			for (size_t j = 0; j < g[ok[i]].size(); ++j)
				printf(" %d", g[ok[i]][j]);
			puts("");
		}
	}
	return 0;
}
