#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> G(n), M(m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &G[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &M[i]);
		sort(G.begin(), G.end());
		sort(M.begin(), M.end());
		int x = 0, y = 0;
		while (x < n && y < m)
			if (G[x] == M[y] || M[y] < G[x])
				++y;
			else
				++x;
		if (x == n)
			puts("MechaGodzilla");
		else
			puts("Godzilla");
	}
	return 0;
}
