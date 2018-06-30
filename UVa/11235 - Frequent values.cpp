#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> node;
#define node(a, b) make_pair(a, b)

struct state{
	node pre, post, cur;
	state(){}
	state(node pre, node post, node cur) :pre(pre), post(post), cur(cur){}
};

const int N = 1e5;
int n, a[N], q;
state seg[N << 2];

inline node max(const node &a, const node &b){
	return a.second > b.second ? a : b;
}

inline state merge(const state &L, const state &R){
	state res;
	res.pre = L.pre;
	res.post = R.post;
	res.cur = max(L.cur, R.cur);
	if (L.post.first == R.pre.first){
		if (res.pre.first == R.pre.first)
			res.pre.second += R.pre.second;
		if (res.post.first == L.post.first)
			res.post.second += L.post.second;
		res.cur = max(res.cur, node(L.post.first, L.post.second + R.pre.second));
		res.cur = max(res.cur, res.pre);
		res.cur = max(res.cur, res.post);
	}
	return res;
}

void build(int p, int l, int r){
	if (l == r){
		seg[p] = state(node(a[l], 1), node(a[l], 1), node(a[l], 1));
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
}

state get(int p, int l, int r, int s, int e){
	if (l >= s && r <= e)
		return seg[p];
	int mid = (l + r) >> 1;
	if (mid >= e)
		return get(p * 2, l, mid, s, e);
	if (mid < s)
		return get(p * 2 + 1, mid + 1, r, s, e);
	return merge(get(p * 2, l, mid, s, e), get(p * 2 + 1, mid + 1, r, s, e));
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0){
		scanf("%d", &q);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		build(1, 0, n - 1);
		while (q-- != 0) {
			int s, e;
			scanf("%d%d", &s, &e);
			--s; --e;
			state res = get(1, 0, n - 1, s, e);
			printf("%d\n", res.cur.second);
		}
	}
	return 0;
}