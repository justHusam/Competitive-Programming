#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 26;
vector<int> g[N];
bool vis[N];

void DFS(int v) {
	vis[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (!vis[u])
			DFS(u);
	}
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		char ch, s[10];
		scanf(" %c", &ch);
		int n = ch - 'A';
		for (int i = 0; i <= n; ++i)
			g[i].clear(), vis[i] = false;
		gets(s);
		while (gets(s) > 0 && strlen(s) != 0) {
			int u = s[0] - 'A';
			int v = s[1] - 'A';
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = 0;
		for (int i = 0; i <= n; ++i)
			if (!vis[i])
				++res, DFS(i);
		printf("%d\n", res);
		if (T != 0)
			puts("");
	}
	return 0;
}
