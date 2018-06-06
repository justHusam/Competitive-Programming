#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 30009;
int n, k;
char s[N];
pair<int, int> seg[N * 4];

void build(int n, int l, int r) {
	if (l == r) {
		seg[n] = make_pair(s[l] == '(', s[l] == ')');
		return;
	}
	build(n * 2, l, (l + r) / 2);
	build(n * 2 + 1, (l + r) / 2 + 1, r);
	const pair<int, int>&a = seg[n * 2], &b = seg[n * 2 + 1];
	int mn = min(a.first, b.second);
	seg[n].first = a.first + b.first - mn;
	seg[n].second = a.second + b.second - mn;
}

int at;
void update(int n, int l, int r) {
	if (at < l || at > r)
		return;
	if (l == r) {
		if (s[l] == ')')
			s[l] = '(';
		else
			s[l] = ')';
		seg[n] = make_pair(s[l] == '(', s[l] == ')');
		return;
	}
	update(n * 2, l, (l + r) / 2);
	update(n * 2 + 1, (l + r) / 2 + 1, r);
	const pair<int, int>&a = seg[n * 2], &b = seg[n * 2 + 1];
	int mn = min(a.first, b.second);
	seg[n].first = a.first + b.first - mn;
	seg[n].second = a.second + b.second - mn;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		getchar();
		for (int i = 1; i <= n; ++i)
			s[i] = getchar();
		build(1, 1, n);
		int m;
		scanf("%d", &m);
		printf("Test %d:\n", ++k);
		while (m-- != 0) {
			int k;
			scanf("%d", &k);
			if (k == 0) {
				if (seg[1].first == 0 && seg[1].second == 0)
					puts("YES");
				else
					puts("NO");
				continue;
			}
			at = k;
			update(1, 1, n);
		}
	}
	return 0;
}
