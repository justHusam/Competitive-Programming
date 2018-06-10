#include <bits/stdc++.h>
using namespace std;

bool vis[20001];

string BFS(int N) {
	string res = "";
	queue<pair<int, int> > qu;
	qu.push(make_pair(1, 1));
	memset(vis, false, sizeof vis);
	vis[1] = true;
	while (!qu.empty()) {
		pair<int, int> e = qu.front();
		qu.pop();
		if (e.first == 0) {
			for (int mask = e.second; mask > 0; mask >>= 1)
				res += (mask & 1) + '0';
			reverse(res.begin(), res.end());
			break;
		}
		for (int i = 0; i < 2; ++i) {
			int nMod = (e.first * 10 + i) % N;
			if (!vis[nMod]) {
				vis[nMod] = true;
				qu.push(make_pair(nMod, (e.second << 1) | i));
			}
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int T, n;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		puts(BFS(n).c_str());
	}
	return 0;
}
