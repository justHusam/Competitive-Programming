#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	string s;
	double p;
	int r, id;
	state(const string &s, double p, int r, int id) :
			s(s), p(p), r(r), id(id) {
	}
	bool operator<(const state &e) const {
		if (e.r != r) {
			return e.r < r;
		}
		if (e.p != p) {
			return p < e.p;
		}
		return id < e.id;
	}
};

char s[100];
vector<state> v;

int main(int argc, char **argv) {
	int n, m, cas = 1;
	while (scanf("%d%d", &n, &m) > 0 && (n != 0 && m != 0)) {
		if (cas != 1)
			puts("");
		v.clear();
		for (int i = 0; i <= n; ++i)
			gets(s);
		double p = -1, d;
		int r;
		for (int i = 0; i < m; ++i) {
			gets(s);
			scanf("%lf%d", &d, &r);
			v.push_back(state(s, d, r, i));
			for (int j = 0; j <= r; ++j)
				gets(s);
		}
		sort(v.begin(), v.end());
		printf("RFP #%d\n%s\n", cas++, v[0].s.c_str());
	}
	return 0;
}
