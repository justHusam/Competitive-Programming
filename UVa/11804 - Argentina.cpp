#include<bits/stdc++.h>
using namespace std;

struct ply {
	char s[30];
	int a, d;
} v[10];

struct state {
	int a, d;
	vector<string> x, y;
	state() {
	}
	state(int a, int d, const vector<string>&x, const vector<string>&y) :
			a(a), d(d), x(x), y(y) {
	}
	bool operator<(const state&e) const {
		if (e.a != a)
			return e.a < a;
		if (e.d != d)
			return e.d < d;
		return e.x > x;
	}
};

vector<state> res;

void calc(int cur, bitset<10> msk) {
	if (msk.count() == 5) {
		int at = 0, df = 0;
		vector<string> x, y;
		for (int i = 0; i < 10; ++i)
			if (msk[i] == 1) {
				x.push_back(v[i].s);
				at += v[i].a;
			} else {
				y.push_back(v[i].s);
				df += v[i].d;
			}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		state st = state(at, df, x, y);
		res.push_back(state(at, df, x, y));
		return;
	}
	if (cur == 10)
		return;
	calc(cur + 1, msk);
	msk[cur] = 1;
	calc(cur + 1, msk);
	msk[cur] = 0;
}

void print(const vector<string>&v) {
	putchar('(');
	string s = "";
	for (int i = 0; i < 5; ++i, s = ", ")
		printf("%s%s", s.c_str(), v[i].c_str());
	puts(")");
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		for (int i = 0; i < 10; ++i)
			scanf("%s%d%d", v[i].s, &v[i].a, &v[i].d);
		res.clear();
		calc(0, 0);
		sort(res.begin(), res.end());
		printf("Case %d:\n", k++);
		print(res[0].x);
		print(res[0].y);
	}
	return 0;
}
