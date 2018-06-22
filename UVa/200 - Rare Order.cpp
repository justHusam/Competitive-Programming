#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char s[99];
int id, in[26];
vector<string> v;
bool vis[26][26], with[26];
vector<int> g[26];
queue<int> qu;

void add(int x, int y) {
	int m = min(v[x].size(), v[y].size());
	for (int i = 0; i < m; ++i)
		if (v[x][i] != v[y][i]) {
			vis[v[x][i] - 'A'][v[y][i] - 'A'] = 1;
			return;
		}
}

int main(int argc, char **argv) {
	while (scanf("%s", s) > 0 && s[0] != '#') {
		v.push_back(s);
		for (int i = 0; s[i]; ++i)
			with[s[i] - 'A'] = 1;
	}
	for (size_t i = 0; i < v.size(); ++i)
		for (size_t j = i + 1; j < v.size(); ++j)
			add(i, j);
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			if (vis[i][j]) {
				++in[j];
				g[i].push_back(j);
			}
	for (int i = 0; i < 26; ++i)
		if (in[i] == 0 && with[i])
			qu.push(i);
	while (!qu.empty()) {
		int v = qu.front();
		qu.pop();
		putchar(v + 'A');
		for (size_t i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (--in[u] == 0)
				qu.push(u);
		}
	}
	puts("");
	return 0;
}
