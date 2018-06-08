#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct state {
	int s, m, p;
	char d;
	state(int s, int m, int p, char d) :
			s(s), m(m), p(p), d(d) {
	}
};

vector<state> qu;
bool vis[1100][1001];

void print(int p) {
	if (p == -1)
		return;
	print(qu[p].p);
	putchar(qu[p].d);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		qu.clear();
		memset(vis, false, sizeof vis);
		bool ok = false;
		for (int i = 1; i < 10 && !ok; ++i) {
			qu.push_back(state(i, i % n, -1, i + '0'));
			vis[i][i % n] = true;
			if (i == n) {
				printf("%d\n", i);
				ok = true;
			}
		}
		size_t pos = 0;
		while (pos < qu.size() && !ok) {
			size_t size = qu.size();
			for (size_t p = pos; pos < size && !ok; ++p) {
				const state t = qu[p];
				for (int i = 0; i < 10; ++i) {
					int s = t.s + i, m = (t.m * 10 + i) % n;
					if (vis[s][m])
						continue;
					vis[s][m] = true;
					qu.push_back(state(s, m, p, i + '0'));
					if (s == n && m == 0) {
						print(qu.size() - 1);
						putchar('\n');
						ok = true;
						break;
					}
				}
			}
			pos = size;
		}
	}
	return 0;
}
