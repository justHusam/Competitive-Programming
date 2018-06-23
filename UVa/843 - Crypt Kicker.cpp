#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 26;
int n, m, hs[N], rhs[N];
string s;
vector<string> dic[17];
bool has[N][N], ok;
vector<int> can[N], node(N, -1);
vector<vector<int> > g;
vector<char> sol;

inline void insert(const string &s) {
	int cur = 0;
	for (int i = 0; i < (int) s.size(); ++i) {
		if (g[cur][s[i] - 'a'] == -1) {
			g[cur][s[i] - 'a'] = g.size();
			g.push_back(node);
		}
		cur = g[cur][s[i] - 'a'];
	}
	dic[s.size()].push_back(s);
}

void calc(int at, int cur) {
	if (ok)
		return;
	if (at == m) {
		ok = true;
		return;
	}
	if (s[at] == ' ') {
		sol.push_back(' ');
		calc(at + 1, 0);
		if (!ok)
			sol.pop_back();
		return;
	}
	int p = s[at] - 'a';
	if (hs[p] == -1) {
		for (int i = 0; i < (int) can[p].size(); ++i) {
			int go = can[p][i];
			int oldHs = rhs[go];
			if (g[cur][go] == -1 || (oldHs != -1 && oldHs != p))
				continue;
			sol.push_back(char(go + 'a'));
			hs[p] = go;
			rhs[go] = p;
			calc(at + 1, g[cur][go]);
			if (ok)
				break;
			rhs[go] = oldHs;
			sol.pop_back();
		}
		hs[p] = -1;
	} else {
		p = hs[p];
		if (g[cur][p] != -1) {
			sol.push_back(char(p + 'a'));
			calc(at + 1, g[cur][p]);
			if (!ok)
				sol.pop_back();
		}
	}
}

int main(int argc, char **argv) {
	g.push_back(node);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		insert(s);
	}
	cin.ignore();
	while (getline(cin, s)) {
		stringstream ss(s);
		string z;
		memset(has, false, sizeof has);
		while (ss >> z) {
			int len = z.size();
			for (int i = 0; i < (int) dic[len].size(); ++i)
				for (int j = 0; j < len; ++j)
					has[z[j] - 'a'][dic[len][i][j] - 'a'] = true;
		}
		for (int i = 0; i < N; ++i) {
			can[i].clear();
			for (int j = 0; j < N; ++j)
				if (has[i][j])
					can[i].push_back(j);
		}
		m = s.size();
		sol.clear();
		ok = false;
		for (int i = 0; i < N; ++i)
			hs[i] = rhs[i] = -1;
		calc(0, 0);
		for (int i = 0; i < m; ++i)
			if (ok)
				printf("%c", sol[i]);
			else {
				if (s[i] == ' ')
					printf(" ");
				else
					printf("*");
			}
		puts("");
	}
	return 0;
}
