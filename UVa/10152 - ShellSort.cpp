#include<bits/stdc++.h>
using namespace std;

const int N = 200;
int n, in[N], st[N], pos[N];
char g[N][N], p[N][N];

void move(int pos) {
	for (int i = pos[pos]; i > 0; --i) {
		st[i] = st[i - 1];
		pos[st[i]] = i;
	}
	st[0] = pos;
	pos[pos] = 0;
}

bool check(int pos) {
	for (int i = 0; i < n; ++i) {
		st[i] = in[i];
		pos[st[i]] = i;
	}
	for (int i = pos; i >= 0; --i)
		move(i);
	for (int i = 0; i < n; ++i)
		if (i != st[i])
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		cin.ignore();
		for (int i = 0; i < n; ++i)
			gets(g[i]);
		map<string, int> hs;
		for (int i = 0; i < n; ++i) {
			gets(p[i]);
			hs[p[i]] = i;
		}
		bool good = true;
		for (int i = 0; i < n; ++i) {
			in[i] = hs[g[i]];
			good &= in[i] == i;
		}
		if (good) {
			puts("");
			continue;
		}
		vector<string> res;
		for (int i = 0; i < n; ++i)
			if (check(i)) {
				for (int j = i; j >= 0; --j) {
					move(j);
					res.push_back(p[j]);
				}
				break;
			}
		for (size_t i = 0; i < res.size(); ++i)
			puts(res[i].c_str());
		puts("");
	}
	return 0;
}
