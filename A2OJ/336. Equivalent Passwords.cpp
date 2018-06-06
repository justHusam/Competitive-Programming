#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n, vis[N], vs, hs[N][6], conv[N];
char s[6], w[6];
vector<string> v;

bool calc(int i, int len, int d) {
	if (len == (int) v[i].size()) {
		w[len] = '\0';
		int m = atoi(w);
		if (hs[m][len] != -1)
			vis[hs[m][len]] = vs;
		return true;
	}
	bool can = false;
	if (v[i][len] - '0' + d < 10) {
		w[len] = char(v[i][len] - '0' + d + '0');
		can |= calc(i, len + 1, d);
	}
	if (v[i][len] - '0' - d > -1) {
		w[len] = char(v[i][len] - '0' - d + '0');
		can |= calc(i, len + 1, d);
	}
	return can;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		memset(hs, -1, sizeof hs);
		v.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int m = atoi(s), len = strlen(s);
			if (hs[m][len] == -1) {
				hs[m][len] = v.size();
				conv[v.size()] = m;
				v.push_back(s);
			}
		}
		n = v.size();
		++vs;
		for (int i = 0; i < n; ++i)
			if (vis[i] != vs)
				for (int j = 1; j < 10; ++j)
					if (!calc(i, 0, j))
						break;
		int res = 0;
		for (int i = 0; i < n; ++i)
			if (vis[i] != vs)
				++res;
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}
