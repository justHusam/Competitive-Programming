#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5;
int n, id, a[N], b[N];
map<ll, int> hs;
vector<multiset<int> > st;

inline void add(int &x) {
	if (hs.find(x) == hs.end())
		hs[x] = id++;
	x = hs[x];
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		id = 0;
		hs.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			add(a[i]);
			add(b[i]);
		}
		st.clear();
		st.resize(id);
		for (int i = 0; i < n; ++i)
			st[a[i]].insert(b[i]);
		bool can = true;
		for (int i = 0; i < n && can; ++i) {
			multiset<int>::iterator it = st[b[i]].find(a[i]);
			if (it == st[b[i]].end())
				can = false;
			else
				st[b[i]].erase(it);
		}
		if (can)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
