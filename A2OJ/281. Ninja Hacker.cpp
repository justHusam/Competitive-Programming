#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
char s[N], ss[100];
int need[26], cum[N][26];
vector<int> nxt[26];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		memset(need, -1, sizeof need);
		int m;
		scanf("%d", &m);
		while (m-- != 0) {
			scanf("%s", ss);
			int len = strlen(ss), i = ss[len - 1] - 'a';
			ss[len - 1] = 0;
			if (need[i] != -1)
				need[i] += atoi(ss);
			else
				need[i] = atoi(ss);
		}
		int all = 0;
		for (int i = 0; i < 26; ++i) {
			nxt[i].clear();
			if (need[i] != -1)
				all += need[i];
		}
		int n = strlen(s);
		if (all > n) {
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 26; ++j)
				cum[i][j] = cum[i - 1][j];
			int k = s[i - 1] - 'a';
			++cum[i][k];
			nxt[k].push_back(i - 1);
		}
		bool can = true;
		for (int i = 0; i < 26 && can; ++i)
			can &= need[i] <= (int) nxt[i].size();
		if (!can) {
			puts("-1");
			continue;
		}
		int res = 2e9;
		for (int i = 0; i < n; ++i) {
			int mx = i;
			bool can = true;
			for (int j = 0; j < 26 && can; ++j) {
				if (need[j] == -1)
					continue;
				int k = lower_bound(nxt[j].begin(), nxt[j].end(), i) - nxt[j].begin();
				if (k + need[j] > (int) nxt[j].size())
					can = false;
				else if (need[j])
					mx = max(mx, nxt[j][k + need[j] - 1]);
			}
			for (int j = 0; j < 26 && can; ++j)
				if (need[j] != -1) {
					int k = cum[mx + 1][j] - cum[i][j];
					can &= k == need[j];
				}
			if (can)
				res = min(res, mx - i + 1);
		}
		if (res == 2e9)
			res = -1;
		printf("%d\n", res);
	}
	return 0;
}
