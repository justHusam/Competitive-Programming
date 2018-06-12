#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	string name;
	vector<pair<int, int> > v;
};

struct ST {
	int s, i;
	string n;
	ST(int s, int i, string n) :
			s(s), i(i), n(n) {
	}
	bool operator<(const ST &e) const {
		if (e.s != s)
			return s > e.s;
		return n < e.n;
	}
};

const int oo = 1e9;
int n;
vector<state> v;
vector<int> all;
vector<ST> g;

void add(string s) {
	state st;
	st.name = s.substr(0, s.find(' '));
	int pos = 0;
	while (pos < (int) s.size()) {
		int k = s.find('/', pos);
		if (k == (int) string::npos)
			break;
		string a = "", b = "";
		for (int i = k - 1;; --i) {
			if (s[i] == ' ')
				break;
			a += s[i];
		}
		for (int i = k + 1;; ++i) {
			if (i == (int) s.size() || s[i] == ' ')
				break;
			b += s[i];
		}
		reverse(a.begin(), a.end());
		st.v.push_back(make_pair(atoi(a.c_str()), atoi(b.c_str())));
		pos = k + 1;
	}
	v.push_back(st);
}

int calc(int d) {
	g.clear();
	for (int i = 0; i < n; ++i) {
		vector<pair<int, int> > &x = v[i].v;
		int with = 0;
		for (size_t j = 0; j < x.size(); ++j)
			if (x[j].second < d)
				with += x[j].first;
		g.push_back(ST(with, i, v[i].name));
	}
	sort(g.begin(), g.end());
	return g[0].i;
}

class ContestScoreboard {
public:
	vector<int> findWinner(vector<string> scores) {
		n = scores.size();
		for (int i = 0; i < n; ++i)
			add(scores[i]);
		for (int i = 0; i < n; ++i) {
			vector<pair<int, int> > &x = v[i].v;
			for (size_t j = 0; j < x.size(); ++j) {
				all.push_back(x[j].second);
				for (int k = -10; k <= 10; ++k) {
					int v = x[j].second + k;
					if (v >= 1 && v <= oo)
						all.push_back(v);
				}
			}
		}
		sort(all.begin(), all.end());
		all.resize(unique(all.begin(), all.end()) - all.begin());
		vector<int> res(n, 0);
		for (size_t i = 0; i < all.size(); ++i) {
			int pos = calc(all[i]);
			res[pos] = 1;
		}
		return res;
	}
};
