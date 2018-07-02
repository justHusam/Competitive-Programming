#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 50;
vector<int> g[N], st;
int low[N], idx[N], id, comp;
char s[1111];
bool in[N];

inline bool check(char a, char b) {
	if (a == 'F' && b == 'M')
		return true;
	if (a == 'M' && b == 'F')
		return true;
	return false;
}

void DFS(int v) {
	in[v] = true;
	low[v] = idx[v] = ++id;
	st.push_back(v);
	for (size_t i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (idx[u] == 0) {
			DFS(u);
			low[v] = min(low[v], low[u]);
		} else if (in[u])
			low[v] = min(low[v], low[u]);
	}
	if (low[v] == idx[v]) {
		int n;
		do {
			n = st.back();
			st.pop_back();
			in[n] = false;
		} while (n != v);
		++comp;
	}
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	getchar();
	while (t-- != 0) {
		gets(s);
		stringstream ss(s);
		vector<string> v;
		string temp;
		while (ss >> temp)
			v.push_back(temp);
		int n = v.size();
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			idx[i] = 0;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j && check(v[i][0], v[j][1]))
					g[i].push_back(j);
		id = comp = 0;
		for (int i = 0; i < n; ++i)
			if (idx[i] == 0)
				DFS(i);
		if (n != 1 && comp == 1)
			puts("LOOP");
		else
			puts("NO LOOP");
	}
	return 0;
}
