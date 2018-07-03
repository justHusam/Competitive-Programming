#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

struct circle {
	double x, y, r;
	circle() {
	}
	circle(double x, double y, double r) :
			x(x), y(y), r(r) {
	}
};

const int N = 100;
vector<vector<int> > g;
int low[N], idx[N];
vector<int> st;
bool in[N];
int id, res;

bool check(const circle&p1, const circle&p2) {
	double x = p1.x - p2.x, y = p1.y - p2.y;
	double d = sqrt(x * x + y * y);
	if (d > p1.r + p2.r || d < fabs(p1.r - p2.r))
		return false;
	return true;
}

void DFS(int v) {
	in[v] = true;
	st.push_back(v);
	low[v] = idx[v] = ++id;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (idx[u] == 0) {
			DFS(u);
			low[v] = min(low[u], low[v]);
		} else if (in[u])
			low[v] = min(low[v], low[u]);
	}
	if (idx[v] == low[v]) {
		int cnt = 0, n;
		do {
			n = st.back();
			st.pop_back();
			in[n] = false;
			++cnt;
		} while (n != v);
		res = max(res, cnt);
	}
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != -1) {
		vector<circle> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf%lf", &v[i].x, &v[i].y, &v[i].r);
		g.clear();
		g.resize(n);
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (check(v[i], v[j])) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
		id = res = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		string prt = "rings";
		if (res == 1)
			prt = "ring";
		printf("The largest component contains %d %s.\n", res, prt.c_str());
	}
	return 0;
}
