#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n, x[N], y[N];

struct state {
	int w, h, m, k;
	state(int w, int h, int m, int k) :
			w(w), h(h), m(m), k(k) {
	}
	bool operator<(const state&e) const {
		if (e.m != m)
			return e.m < m;
		if (e.w != w)
			return e.w < w;
		return e.k < k;
	}
};

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", x + i, y + i);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", k++);
		while (q-- != 0) {
			int rx, ry;
			scanf("%d%d", &rx, &ry);
			priority_queue<state> qu;
			for (int i = 0; i < n; ++i)
				if (rx % x[i] == 0 && ry % y[i] == 0 && rx / x[i] == ry / y[i])
					qu.push(state(rx, ry, rx * ry, 0));
			for (int i = 0; i < n; ++i)
				if (ry % x[i] == 0 && rx % y[i] == 0 && ry / x[i] == rx / y[i])
					qu.push(state(ry, rx, ry * rx, 1));
			for (int i = 0; i < n; ++i)
				for (int j = 1; j <= 200; ++j)
					if (rx <= x[i] * j && ry <= y[i] * j) {
						qu.push(state(x[i] * j, y[i] * j, j * x[i] * j * y[i], 1));
						break;
					}
			for (int i = 0; i < n; ++i)
				for (int j = 1; j <= 200; ++j)
					if (ry <= x[i] * j && rx <= y[i] * j) {
						qu.push(state(x[i] * j, y[i] * j, x[i] * j * y[i] * j, 2));
						break;
					}
			printf("%d %d %d\n", qu.top().w, qu.top().h, qu.top().k);
		}
	}
	return 0;
}
