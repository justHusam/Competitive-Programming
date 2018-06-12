#include <bits/stdc++.h>
using namespace std;

class ABBA {
public:
	string canObtain(string initial, string target) {
		if (check(initial, target))
			return "Possible";
		return "Impossible";
	}

	bool check(string &from, string &to) {
		int a1 = 0, b1 = 0, a2 = 0, b2 = 0, n = from.size(), m = to.size();
		for (int i = 0; i < n; ++i)
			if (from[i] == 'A')
				++a1;
			else
				++b1;
		for (int i = 0; i < m; ++i)
			if (to[i] == 'A')
				++a2;
			else
				++b2;
		while (n < m) {
			if (a2 < a1 || b2 < b1)
				return false;
			char c = to[m - 1];
			to.erase(to.size() - 1);
			if (c == 'A') {
				--a2;
				--m;
			} else {
				--b2;
				--m;
				reverse(to.begin(), to.end());
			}
		}
		return from == to;
	}
};
