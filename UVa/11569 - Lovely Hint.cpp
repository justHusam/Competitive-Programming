#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

vector<char> v;
int mx, cnt;

inline void calc(int i, int w, char ch) {
	if (i == (int) v.size()) {
		if (w > mx)
			mx = w, cnt = 0;
		cnt += w == mx;
		return;
	}
	calc(i + 1, w, ch);
	if (ch == 'a' || (v[i] - 'A' + 1) * 4 >= (ch - 'A' + 1) * 5)
		calc(i + 1, w + 1, v[i]);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	getchar();
	while (t-- != 0) {
		char s[300];
		gets(s);
		bool vis[26] = { };
		v.clear();
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			if (isalpha(s[i]) && !vis[s[i] - 'A']) {
				v.push_back(s[i]);
				vis[s[i] - 'A'] = true;
			}
		sort(v.begin(), v.end());
		mx = -1;
		cnt = 0;
		calc(0, 0, 'a');
		if (mx == 0)
			cnt = 0;
		printf("%d %d\n", mx, cnt);
	}
	return 0;
}
