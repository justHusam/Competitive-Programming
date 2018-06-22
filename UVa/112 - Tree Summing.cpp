#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum;
vector<int> v;
vector<vector<int> > g;

bool calc(int n, int w) {
	if (g[n].empty())
		return w == sum;
	bool can = false;
	for (size_t i = 0; i < g[n].size() && !can; ++i)
		can |= calc(g[n][i], w + v[g[n][i]]);
	return can;
}

string read() {
	string res = "";
	char c = getchar();
	while (c == ' ')
		c = getchar();
	res += '(';
	int open = 1;
	while (open) {
		c = getchar();
		while (c == ' ' || c == '\n')
			c = getchar();
		res += c;
		if (c == '(')
			++open;
		else if (c == ')')
			--open;
	}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &sum) > 0) {
		string s = read();
		v.clear();
		g.clear();
		vector<int> st(1, -1);
		v.push_back(-1);
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				st.push_back(v.size());
				v.push_back(-1);
				g.push_back(vector<int>());
			} else if (s[i] == ')')
				st.pop_back();
			else {
				int x = 0, p = 1;
				if (s[i] == '-')
					p = -1, ++i;
				while (isdigit(s[i]))
					x = x * 10 + (s[i++] - '0');
				--i;
				v.back() = x * p;
				if (st[st.size() - 2] != -1)
					g[st[st.size() - 2]].push_back(v.size() - 1);
			}
		}
		if (g.size() > 1 && calc(1, v[1]))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
