#include <bits/stdc++.h>
using namespace std;

struct state {
	char t;
	int a, b;
	state(char t, int a, int b) :
			t(t), a(a), b(b) {
	}
};

const int N = 2e4;
int n, q, par[N], p[N];
vector<state> v;
set<pair<int, int> > E;
set<pair<int, int> >::iterator it;
vector<bool> res;

int find(int x) {
	if (x == par[x])
		return par[x];
	return par[x] = find(par[x]);
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &q);
		E.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
			--p[i];
			par[i] = i;
			if (p[i] != -1)
				E.insert(make_pair(min(i, p[i]), max(i, p[i])));
		}
		v.clear();
		char c;
		int a, b;
		while (q-- != 0) {
			scanf(" %c", &c);
			if (c == 'C') {
				scanf("%d", &a);
				--a;
				b = p[a];
				if (b == -1)
					continue;
				it = E.find(make_pair(min(a, b), max(a, b)));
				if (it != E.end()) {
					v.push_back(state(c, a, b));
					E.erase(it);
				}
			} else {
				scanf("%d%d", &a, &b);
				--a;
				--b;
				v.push_back(state(c, a, b));
			}
		}
		for (it = E.begin(); it != E.end(); ++it) {
			int u = find((*it).first);
			int v = find((*it).second);
			par[u] = v;
		}
		res.clear();
		reverse(v.begin(), v.end());
		for (size_t i = 0; i < v.size(); ++i)
			if (v[i].t == 'C') {
				int a = find(v[i].a);
				int b = find(v[i].b);
				par[a] = b;
			} else {
				int a = find(v[i].a);
				int b = find(v[i].b);
				res.push_back(a == b);
			}
		reverse(res.begin(), res.end());
		printf("Case #%d:\n", cas++);
		for (size_t i = 0; i < res.size(); ++i)
			if (res[i])
				puts("YES");
			else
				puts("NO");
	}
	return 0;
}
