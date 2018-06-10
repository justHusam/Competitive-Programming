#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 40000;
int n, l[N], r[N];
vector<vector<int> > s, e;
vector<int> hs;
set<int> st, sol;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		hs.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &l[i], &r[i]);
			hs.push_back(l[i]);
			hs.push_back(r[i]);
		}
		sort(hs.begin(), hs.end());
		hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
		s.clear();
		s.resize(hs.size());
		e.clear();
		e.resize(hs.size());
		for (int i = 0; i < n; ++i) {
			int L = lower_bound(hs.begin(), hs.end(), l[i]) - hs.begin();
			int R = lower_bound(hs.begin(), hs.end(), r[i]) - hs.begin();
			s[L].push_back(i);
			e[R].push_back(i);
		}
		st.clear();
		sol.clear();
		for (int i = 0; i < hs.size(); ++i) {
			for (int j = 0; j < s[i].size(); ++j)
				st.insert(s[i][j]);
			sol.insert(*(--st.end()));
			for (int j = 0; j < e[i].size(); ++j)
				st.erase(e[i][j]);
		}
		printf("%d\n", (int) sol.size());
	}
	return 0;
}
