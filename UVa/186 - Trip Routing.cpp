#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<pair<pair<string, string>, pair<string, int> > > all;
int path[N];
map<string, int> hs, rt;

int pos(int p, string & str, const string & line) {
	int i = line.find(',', p);
	str = line.substr(p, i - p);
	return i + 1;
}

inline void putsp(int n) {
	while (n-- != 0)
		putchar(' ');
}

void print(int v) {
	if (v == -1) {
		puts("From                 To                   Route      Miles");
		puts("-------------------- -------------------- ---------- -----");
		return;
	}
	int c = all[v].second.second;
	string i = all[v].first.first, j = all[v].first.second, r = all[v].second.first;
	print(path[hs[i]]);
	printf("%s", i.c_str());
	putsp(21 - i.size());
	printf("%s", j.c_str());
	putsp(21 - j.size());
	printf("%s", r.c_str());
	putsp(11 - r.size());
	printf("%5d\n", c);
}

int main(int argc, char **argv) {
	string line;
	int s1 = 0, s2 = 0, k = 0;
	vector<pair<int, int> > g[N];
	while (getline(cin, line) && !line.empty()) {
		int p = 0, c, u, v;
		string i, j, r, w;
		p = pos(p, i, line), p = pos(p, j, line);
		p = pos(p, r, line), p = pos(p, w, line);
		if (hs.find(i) == hs.end())
			hs[i] = s1++;
		if (hs.find(j) == hs.end())
			hs[j] = s1++;
		if (rt.find(r) == rt.end())
			rt[r] = s2++;
		c = atoi(w.c_str()), u = hs[i], v = hs[j];
		g[u].push_back( { v, k++ });
		g[v].push_back( { u, k++ });
		all.push_back( { { i, j }, { r, c } });
		all.push_back( { { j, i }, { r, c } });
	}
	while (getline(cin, line)) {
		puts("\n");
		int p = 0, str, tar;
		string s, e;
		p = pos(p, s, line), p = pos(p, e, line);
		str = hs[s], tar = hs[e];
		bitset<N> vis;
		vector<int> cost(N, 1 << 30);
		priority_queue<pair<int, int> > qu;
		memset(path, -1, sizeof path);
		vis.reset();
		cost[str] = 0;
		qu.push( { 0, str });
		while (!qu.empty()) {
			pair<int, int> e = qu.top();
			qu.pop();
			if (e.second == tar) {
				print(path[tar]);
				puts("                                                     -----");
				printf("                                          Total      %5d\n", -e.first);
				break;
			}
			if (vis[e.second])
				continue;
			vis[e.second] = 1;
			for (size_t i = 0; i < g[e.second].size(); ++i) {
				int v = g[e.second][i].first, p = g[e.second][i].second;
				int c = -e.first + all[p].second.second;
				if (vis[v] || c >= cost[v])
					continue;
				cost[v] = c;
				path[v] = p;
				qu.push( { -c, v });
			}
		}
	}
	return 0;
}
