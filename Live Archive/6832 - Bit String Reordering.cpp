#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, a[15];
bool vis[1 << 15];

inline bool check(const bitset<15>&bs) {
	int w = 1, at = 0;
	for (int i = 1; i < n; ++i) {
		if (bs[i] == bs[i - 1])
			++w;
		else {
			if (w != a[at])
				return false;
			w = 1;
			++at;
		}
	}
	return w == a[at] && at + 1 == m;
}

int BFS(bitset<15> src) {
	if (check(src))
		return 0;
	queue<int> qu;
	qu.push(src.to_ulong());
	vis[src.to_ulong()] = true;
	int lev = 1;
	while (!qu.empty()) {
		int sz = qu.size();
		while (sz-- != 0) {
			bitset<15> bs = qu.front();
			qu.pop();
			for (int i = 1; i < n; ++i)
				if (bs[i] != bs[i - 1]) {
					bs[i].flip();
					bs[i - 1].flip();
					int msk = bs.to_ulong();
					if (!vis[msk]) {
						if (check(bs))
							return lev;
						qu.push(msk);
						vis[msk] = true;
					}
					bs[i].flip();
					bs[i - 1].flip();
				}
		}
		++lev;
	}
	return -1;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0) {
		bitset<15> src = 0;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			src[i] = x;
		}
		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		memset(vis, false, sizeof vis);
		printf("%d\n", BFS(src));
	}
	return 0;
}
