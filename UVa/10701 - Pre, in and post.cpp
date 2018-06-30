#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, idx;
char a[53], b[53];
map<char, int> hs;
map<int, char> g;
bool vis[52];
string res;

void build(int s, int e, int p) {
	if (idx == n)
		return;
	g[p] = a[idx];
	if (s == e)
		return;
	int m = hs[a[idx]];
	if (m - 1 >= s) {
		++idx;
		build(s, m - 1, p * 2);
	}
	if (m + 1 <= e) {
		++idx;
		build(m + 1, e, p * 2 + 1);
	}
}

void go(int n) {
	if (g.find(n) == g.end())
		return;
	go(n * 2);
	go(n * 2 + 1);
	res += g[n];
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%s%s", &n, a, b);
		hs.clear();
		for (int i = 0; i < n; ++i)
			hs[b[i]] = i;
		g.clear();
		idx = 0;
		build(0, n - 1, 1);
		res = "";
		go(1);
		puts(res.c_str());
	}
	return 0;
}
