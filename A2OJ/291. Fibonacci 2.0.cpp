#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int a, b, x;
	ll diff;
	state(int a, int b, int x, ll diff) :
			a(a), b(b), x(x), diff(diff) {
	}
	bool operator<(const state&e) const {
		if (e.diff != diff)
			return diff < e.diff;
		if (e.a != a)
			return a < e.a;
		if (e.b != b)
			return b < e.b;
		return x < e.x;
	}
};

const ll N = 1e18;
map<ll, int> A, B, X;
set<ll> st;
vector<ll> v;
vector<int> a, b, x;

void build(int a, int b) {
	if (a == 0 && b == 0)
		return;
	vector<ll> v;
	v.push_back(a);
	v.push_back(b);
	while (true) {
		ll x = v[v.size() - 1] + v[v.size() - 2];
		v.push_back(x);
		if (x > N)
			break;
	}
	for (size_t i = 0; i < v.size(); ++i)
		if (st.find(v[i]) == st.end()) {
			A[v[i]] = a;
			B[v[i]] = b;
			X[v[i]] = i;
			st.insert(v[i]);
		}
}

int main(int argc, char **argv) {
	for (int i = 0; i <= 100; ++i)
		for (int j = i; j <= 100; ++j)
			build(i, j);
	set<ll>::iterator it;
	for (it = st.begin(); it != st.end(); ++it) {
		v.push_back(*it);
		a.push_back(A[*it]);
		b.push_back(B[*it]);
		x.push_back(X[*it]);
	}
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		ll n;
		scanf("%lld", &n);
		vector<state> res;
		res.push_back(state(0, 0, 0, n));
		int k = lower_bound(v.begin(), v.end(), n) - v.begin();
		res.push_back(state(a[k], b[k], x[k], v[k] - n));
		--k;
		if (k >= 0)
			res.push_back(state(a[k], b[k], x[k], n - v[k]));
		sort(res.begin(), res.end());
		printf("Case %d: %d %d %d\n", cas++, res[0].a, res[0].b, res[0].x);
	}
	return 0;
}
