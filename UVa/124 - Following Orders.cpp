#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
vector<char> aa, bb;
int n;
vector<int> g[N];
char res[N + 1];

void get(string&a, vector<char>&res) {
	res.clear();
	stringstream ss(a);
	char ch;
	while (ss >> ch)
		res.push_back(ch);
}

inline bool check(bitset<N> msk, int i) {
	bool res = true;
	for (size_t j = 0; j < g[i].size() && res; ++j)
		res &= msk[g[i][j]];
	return res;
}

void calc(bitset<N> msk, int len) {
	if (len == n) {
		puts(res);
		return;
	}
	for (int i = 0; i < n; ++i)
		if (!msk[i] && check(msk, i)) {
			res[len] = aa[i];
			msk[i] = 1;
			calc(msk, len + 1);
			msk[i] = 0;
		}
}

int main(int argc, char **argv) {
	string a, b;
	bool newLine = false;
	while (getline(cin, a)) {
		if (newLine)
			puts("");
		newLine = true;
		getline(cin, b);
		get(a, aa);
		get(b, bb);
		map<char, int> hs;
		sort(aa.begin(), aa.end());
		n = aa.size();
		for (int i = 0; i < n; ++i)
			hs[aa[i]] = i, g[i].clear();
		for (size_t i = 1; i < bb.size(); i += 2)
			g[hs[bb[i]]].push_back(hs[bb[i - 1]]);
		res[n] = '\0';
		calc(0, 0);
	}
	return 0;
}
