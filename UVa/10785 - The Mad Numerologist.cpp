#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int v, t, c;
	state(int v, int t, int c) :
			v(v), t(t), c(c) {
	}
	bool operator<(const state&e) const {
		if (e.v != v)
			return e.v < v;
		return e.c < c;
	}
};

int val[26], n;
priority_queue<state> A, B;

int main(int argc, char **argv) {
	for (int i = 0; i < 26; ++i)
		val[i] = i % 9 + 1;
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		while (!A.empty())
			A.pop();
		while (!B.empty())
			B.pop();
		for (int i = 0; i < 26; ++i)
			if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
				B.push(state(val[i], 21, i));
			else
				A.push(state(val[i], 5, i));
		string c = "", v = "";
		for (int i = 0; i < n; ++i) {
			if ((i & 1) == 1) {
				state e = A.top();
				A.pop();
				c += char(e.c + 'A');
				if (--e.t != 0)
					A.push(e);
			} else {
				state e = B.top();
				B.pop();
				v += char(e.c + 'A');
				if (--e.t != 0)
					B.push(e);
			}
		}
		sort(c.begin(), c.end());
		sort(v.begin(), v.end());
		string sol = "";
		int x = 0, y = 0;
		for (int i = 0; i < n; ++i) {
			if ((i & 1) == 1) {
				assert(x < (int ) c.size());
				sol += c[x++];
			} else {
				assert(y < (int ) v.size());
				sol += v[y++];
			}
		}
		printf("Case %d: %s\n", cas++, sol.c_str());
	}
	return 0;
}
