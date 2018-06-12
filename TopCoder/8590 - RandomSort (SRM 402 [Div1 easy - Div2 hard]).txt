#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class RandomSort {
public:

	int n, id;
	map<pair<int, int>, double> dp;
	vector<vector<int> > g;
	vector<int> v, hs;

	double getExpected(vector<int> permutation) {
		v = permutation;
		n = v.size();
		g.push_back(vector<int>(8, -1));
		hs.push_back(-1);
		return calc(0);
	}

	int get() {
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (g[cur][v[i] - 1] == -1) {
				g[cur][v[i] - 1] = g.size();
				g.push_back(vector<int>(8, -1));
				hs.push_back(-1);
			}
			cur = g[cur][v[i] - 1];
		}
		if (hs[cur] == -1)
			hs[cur] = id++;
		return hs[cur];
	}

	double calc(int m) {
		bool can = true;
		for (int i = 1; i < n && can; ++i)
			can &= v[i] - 1 == v[i - 1];
		if (can)
			return m;
		int hs = get();
		if (dp.find(make_pair(m, hs)) != dp.end())
			return dp[make_pair(m, hs)];
		double res = 0, all = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				all += v[i] > v[j];
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				if (v[i] < v[j])
					continue;
				swap(v[i], v[j]);
				res += calc(m + 1) * (1 / all);
				swap(v[i], v[j]);
			}
		return dp[make_pair(m, hs)] = res;
	}
};
