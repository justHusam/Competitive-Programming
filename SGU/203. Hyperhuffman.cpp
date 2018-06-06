#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, Q[1000000];
ll v[500000];
vector<int> g[1000000];

ll BFS(int src) {
	int l = 0, r = 0;
	Q[r++] = src;
	ll res = 0, lev = 0;
	while (l < r) {
		int siz = r - l;
		while (siz--) {
			int fr = Q[l++];
			if (fr < n)
				res += lev * v[fr];
			for (size_t i = 0; i < g[fr].size(); ++i) {
				Q[r++] = g[fr][i];
			}
		}
		++lev;
	}
	return res;
}

int get(ll a, ll b, ll c, ll d) {
	ll r1 = a + b;
	ll r2 = a + c;
	ll r3 = c + d;
	ll mn = min(r1, min(r2, r3));
	if (mn == r1)
		return 0;
	if (mn == r2)
		return 1;
	return 2;
}

int main() {
//	freopen("a", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &v[i]);
	deque<pair<ll, int> > qu;
	int at = 2, id = n;
	qu.push_front(make_pair(v[0] + v[1], id));
	g[id].push_back(0);
	g[id].push_back(1);
	++id;
	while (at < n || qu.size() > 1) {
		if (at + 1 < n) {
			if (qu.size() == 0) {
				qu.push_back(make_pair(v[at] + v[at + 1], id));
				g[id].push_back(at);
				g[id].push_back(at + 1);
				at += 2;
				++id;
			} else if (qu.size() == 1) {
				int x = get(v[at], v[at + 1], qu.front().first, 1e15);
				if (x == 0) {
					qu.push_back(make_pair(v[at] + v[at + 1], id));
					g[id].push_back(at);
					g[id].push_back(at + 1);
					at += 2;
					++id;
				} else if (x == 1) {
					qu.push_back(make_pair(v[at] + qu.front().first, id));
					g[id].push_back(at);
					g[id].push_back(qu.front().second);
					++at;
					++id;
					qu.pop_front();
				}
			} else {
				pair<ll, int> a = qu.front();
				qu.pop_front();
				pair<ll, int> b = qu.front();
				qu.pop_front();
				int x = get(v[at], v[at + 1], a.first, b.first);
				if (x == 0) {
					qu.push_back(make_pair(v[at] + v[at + 1], id));
					g[id].push_back(at);
					g[id].push_back(at + 1);
					at += 2;
					++id;
					qu.push_front(b);
					qu.push_front(a);
				} else if (x == 1) {
					qu.push_back(make_pair(v[at] + a.first, id));
					g[id].push_back(at);
					g[id].push_back(a.second);
					++at;
					++id;
					qu.push_front(b);
				} else {
					qu.push_back(make_pair(a.first + b.first, id));
					g[id].push_back(a.second);
					g[id].push_back(b.second);
					++id;
				}
			}
			continue;
		}
		if (at < n) {
			if (qu.size() == 1) {
				qu.push_back(make_pair(v[at] + qu.front().first, id));
				g[id].push_back(at);
				g[id].push_back(qu.front().second);
				++at;
				++id;
				qu.pop_front();
			} else {
				pair<ll, int> a = qu.front();
				qu.pop_front();
				pair<ll, int> b = qu.front();
				qu.pop_front();
				int x = get(v[at], 1e15, a.first, b.first);
				if (x == 1) {
					qu.push_back(make_pair(v[at] + a.first, id));
					g[id].push_back(at);
					g[id].push_back(a.second);
					++at;
					++id;
					qu.push_front(b);
				} else {
					qu.push_back(make_pair(a.first + b.first, id));
					g[id].push_back(a.second);
					g[id].push_back(b.second);
					++id;
				}
			}
			continue;
		}
		pair<ll, int> a = qu.front();
		qu.pop_front();
		pair<ll, int> b = qu.front();
		qu.pop_front();
		qu.push_back(make_pair(a.first + b.first, id));
		g[id].push_back(a.second);
		g[id].push_back(b.second);
		++id;
	}
	cout << BFS(qu.front().second) << "\n";
	return 0;
}
