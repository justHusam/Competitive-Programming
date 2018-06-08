#include <bits/stdc++.h>
using namespace std;

int n, t;
int tm[52][52], toll[52][52];

void Dijkstra(int str, int tar) {
	priority_queue<pair<int, pair<int, int> > > qu;
	qu.push(make_pair(0, make_pair(0, str)));
	while (!qu.empty()) {
		pair<int, pair<int, int> > temp = qu.top();
		qu.pop();
		if (temp.second.second == tar) {
			printf("%d %d\n", temp.first * -1, temp.second.first * -1);
			return;
		}
		for (int i = 0; i < n; ++i) {
			pair<int, int> ct;
			ct.first = temp.first * -1 + toll[temp.second.second][i];
			ct.second = temp.second.first * -1 + tm[temp.second.second][i];
			if (ct.second <= t && i != temp.second.second)
				qu.push(make_pair(ct.first * -1, make_pair(ct.second * -1, i)));
		}
	}
}

int main(int argc, char **argv) {
	while (true) {
		scanf("%d%d", &n, &t);
		if (n == 0 && t == 0)
			break;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &tm[i][j]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &toll[i][j]);
		Dijkstra(0, n - 1);
	}
	return 0;
}
