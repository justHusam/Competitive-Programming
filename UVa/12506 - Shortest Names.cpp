#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

vector<vector<int> > g;
string s[1000];

void insert(string &s) {
	int cur = 0;
	for (int i = 0; s[i]; ++i) {
		if (g[cur][s[i] - 'a'] == -1) {
			g[cur][s[i] - 'a'] = g.size();
			g.push_back(vector<int>(26, -1));
		}
		cur = g[cur][s[i] - 'a'];
	}
}

bool check(int cur) {
	int res = 0;
	for (int i = 0; i < 26 && res < 2; ++i)
		res += g[cur][i] != -1;
	return res < 2;
}

int find(string &s) {
	int cur = 0;
	vector<int> v;
	for (int i = 0; s[i]; ++i) {
		cur = g[cur][s[i] - 'a'];
		v.push_back(check(cur));
	}
	while (v.back() == 1)
		v.pop_back();
	return v.size() + 1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		g.clear();
		g.push_back(vector<int>(26, -1));
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			insert(s[i]);
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
			res += find(s[i]);
		printf("%d\n", res);
	}
	return 0;
}
