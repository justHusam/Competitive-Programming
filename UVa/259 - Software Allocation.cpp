#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

int main(int argc, char **argv) {
	char src[100];
	while (gets(src)) {
		int g[40][40] = { }, req = 0, len = strlen(src);
		bool in[40][40] = { };
		do {
			g[0][src[0] - 'A' + 1] = src[1] - '0';
			req += src[1] - '0';
			for (int i = 3; i < len - 1; ++i) {
				in[src[0] - 'A' + 1][src[i] - '0' + 27] = 1;
				g[src[0] - 'A' + 1][src[i] - '0' + 27] = 1;
			}
		} while (gets(src) && (len = strlen(src)));
		for (int i = 0; i < 10; ++i)
			g[i + 27][37] = 1;
		int src = 0, sink = 37, flow = 0;
		while (true) {
			int temp = oo;
			vector<int> cost(40, 0), par(40, -1);
			priority_queue<pair<int, int> > qu;
			qu.push( { oo, src });
			bitset<40> vis;
			vis.reset();
			while (!qu.empty()) {
				pair<int, int> e = qu.top();
				qu.pop();
				if (vis[e.second])
					continue;
				vis[e.second] = 1;
				if (e.second == sink) {
					temp = e.first;
					break;
				}
				for (int i = 0; i < 38; ++i) {
					if (vis[i] || g[e.second][i] <= cost[i])
						continue;
					cost[i] = min(g[e.second][i], e.first);
					qu.push( { cost[i], i });
					par[i] = e.second;
				}
			}
			if (temp == oo)
				break;
			flow += temp;
			for (int v = sink; v != src; v = par[v]) {
				int u = par[v];
				g[u][v] -= temp;
				g[v][u] += temp;
			}
		}
		if (flow != req) {
			puts("!");
			continue;
		}
		string res(10, '_');
		for (int i = 1; i < 27; ++i) {
			for (int j = 0; j < 10; j++) {
				if (!in[i][j + 27] || g[i][j + 27])
					continue;
				res[j] = char(i - 1 + 'A');
			}
		}
		puts(res.c_str());
	}
	return 0;
}
