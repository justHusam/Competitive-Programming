#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int h, m, s;
	char t;
	state(int h, int m, int s, char t) :
			h(h), m(m), s(s), t(t) {
	}
	bool operator<(const state&e) const {
		if (e.h != h)
			return h < e.h;
		if (e.m != m)
			return m < e.m;
		return s < e.s;
	}
};

int n;
vector<state> v;
char a[111];
vector<char> vv;

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		v.clear();
		for (int i = 0; i < n; ++i) {
			char t;
			scanf("%s %c", a, &t);
			string ss = a;
			int h = atoi(ss.substr(0, 2).c_str());
			int m = atoi(ss.substr(3, 2).c_str());
			int s = atoi(ss.substr(6, 2).c_str());
			v.push_back(state(h, m, s, t));
		}
		sort(v.begin(), v.end());
		int enter = 0;
		deque<int> qu;
		vv.clear();
		vv.resize(n);
		for (int i = 0; i < n; ++i) {
			if (v[i].t == '?') {
				qu.push_back(i);
				continue;
			}
			if (v[i].t == 'E') {
				vv[i] = 'E';
				++enter;
				continue;
			}
			if (enter == 0) {
				int fr = qu.front();
				qu.pop_front();
				vv[fr] = 'E';
				vv[i] = 'X';
			} else {
				vv[i] = 'X';
				--enter;
			}
		}
		while (enter-- > 0) {
			int fr = qu.back();
			qu.pop_back();
			vv[fr] = 'X';
		}
		int sz = qu.size() / 2;
		while (!qu.empty()) {
			int fr = qu.front();
			qu.pop_front();
			if (sz > 0) {
				--sz;
				vv[fr] = 'E';
			} else
				vv[fr] = 'X';
		}
		int mx = 0, w = 0;
		for (int i = 0; i < n; ++i) {
			if (vv[i] == 'E')
				++w;
			else
				--w;
			mx = max(mx, w);
		}
		printf("%d\n", mx);
	}
	return 0;
}
