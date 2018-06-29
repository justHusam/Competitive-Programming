#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> all;

inline void add(string &s, int x) {
	if (x < 10) {
		s += "0";
		s += char(x + '0');
	} else {
		s += char((x / 10) + '0');
		s += char((x % 10) + '0');
	}
}

inline bool check(const string &s) {
	int l = 0, r = (int) s.size() - 1;
	while (l <= r && s[l] == s[r])
		++l, --r;
	return l > r;
}

int main(int argc, char **argv) {
	for (int i = 0; i <= 23; ++i)
		for (int j = 0; j <= 59; ++j) {
			string s = "";
			add(s, i);
			add(s, j);
			while (!s.empty() && s[0] == '0')
				s.erase(0, 1);
			if (s.empty())
				s = "0";
			if (check(s))
				all.push_back(i * 60 + j);
		}
	sort(all.begin(), all.end());
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int h, m;
		scanf("%d:%d", &h, &m);
		int x = h * 60 + m;
		int k = upper_bound(all.begin(), all.end(), x) - all.begin();
		if (k == (int) all.size())
			k = 0;
		m = all[k] % 60;
		h = all[k] / 60;
		printf("%02d:%02d\n", h, m);
	}
	return 0;
}
