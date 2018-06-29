#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[1001];
int n, mx, at;
vector<vector<int> > g;
vector<int> node(4, -1), freq, p;
vector<char> info;

char get(char c) {
	if (c == 'A')
		return 'a';
	if (c == 'C')
		return 'b';
	if (c == 'G')
		return 'c';
	if (c == 'T')
		return 'd';
	if (c == 'a')
		return 'A';
	if (c == 'b')
		return 'C';
	if (c == 'c')
		return 'G';
	return 'T';
}

void insert(int l) {
	int cur = 0;
	for (int i = l; i < n; ++i) {
		if (g[cur][s[i] - 'a'] == -1) {
			g[cur][s[i] - 'a'] = g.size();
			g.push_back(node);
			freq.push_back(0);
			info.push_back(get(s[i]));
		}
		cur = g[cur][s[i] - 'a'];
		++freq[cur];
	}
}

void DFS(int cur, int len) {
	if (len > mx && freq[cur] > 1) {
		mx = len;
		at = cur;
	}
	for (int i = 0; i < 4; ++i)
		if (g[cur][i] != -1) {
			p[g[cur][i]] = cur;
			DFS(g[cur][i], len + 1);
		}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			s[i] = get(s[i]);
		g.clear();
		g.push_back(node);
		freq.clear();
		freq.push_back(0);
		info.clear();
		info.push_back('X');
		for (int i = 0; i < n; ++i)
			insert(i);
		p.clear();
		p.resize(g.size());
		p[0] = -1;
		mx = at = -1;
		DFS(0, 0);
		if (mx == -1) {
			puts("No repetitions found!");
			continue;
		}
		string res;
		int cnt = freq[at];
		do {
			res += info[at];
			at = p[at];
		} while (at != 0);
		reverse(res.begin(), res.end());
		printf("%s %d\n", res.c_str(), cnt);
	}
	return 0;
}
