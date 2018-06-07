#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int n, q;
vector<int> node(26, -1);
vector<vector<int> > g;
char s[1111], res[30];
vector<bool> end;
 
void insert(char *s) {
	int n = strlen(s), cur = 0;
	for (int i = 0; i < n; ++i) {
		if (g[cur][s[i] - 'a'] == -1) {
			g[cur][s[i] - 'a'] = g.size();
			g.push_back(node);
			end.push_back(false);
		}
		cur = g[cur][s[i] - 'a'];
	}
	end[cur] = true;
}
 
void DFS(int cur, int len, bool f) {
	if (end[cur] && f) {
		res[len] = '\0';
		puts(res);
	}
	for (int i = 0; i < 26; ++i)
		if (g[cur][i] != -1) {
			res[len] = char(i + 'a');
			DFS(g[cur][i], len + 1, true);
		}
}
 
int main() {
//	freopen("a", "r", stdin);
	scanf("%d", &n);
	g.push_back(node);
	end.push_back(false);
	while (n--) {
		scanf("%s", s);
		insert(s);
	}
	scanf("%d", &q);
	int cas = 1;
	while (q--) {
		scanf("%s", s);
		int cur = 0, n = strlen(s);
		for (int i = 0; i < n; ++i) {
			if (g[cur][s[i] - 'a'] == -1) {
				cur = -1;
				break;
			}
			cur = g[cur][s[i] - 'a'];
			res[i] = s[i];
		}
		printf("Case #%d:\n", cas++);
		if (cur == -1)
			puts("No match.");
		else
			DFS(cur, n, false);
	}
	return 0;
} 