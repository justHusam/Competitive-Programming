#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, int> hs;
string s;
set<int> st;

bool insert(int i, int n, int v) {
	st.insert(n);
	if (i == (int) s.size()) {
		if (hs.find(n) != hs.end())
			return false;
		hs[n] = v;
		return true;
	}
	if (s[i] == 'L')
		return insert(i + 1, n * 2, v);
	return insert(i + 1, n * 2 + 1, v);
}

int main(int argc, char **argv) {
	while (cin >> s) {
		hs.clear();
		st.clear();
		bool good = true;
		do {
			int k = s.find(',');
			int v = atoi(s.substr(1, k - 1).c_str());
			s = s.substr(k + 1);
			s.erase(s.size() - 1);
			good &= insert(0, 1, v);
			cin >> s;
		} while (s != "()");
		set<int>::iterator it;
		for (it = st.begin(); it != st.end() && good; ++it)
			if (hs.find(*it) == hs.end())
				good = false;
		if (!good) {
			puts("not complete");
			continue;
		}
		queue<int> qu;
		vector<int> res;
		qu.push(1);
		while (!qu.empty()) {
			int fr = qu.front();
			qu.pop();
			res.push_back(hs[fr]);
			if (hs.find(fr * 2) != hs.end())
				qu.push(fr * 2);
			if (hs.find(fr * 2 + 1) != hs.end())
				qu.push(fr * 2 + 1);
		}
		for (size_t i = 0; i < res.size(); ++i)
			printf("%s%d", i ? " " : "", res[i]);
		puts("");
	}
	return 0;
}
