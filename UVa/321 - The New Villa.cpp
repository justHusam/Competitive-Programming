#include <bits/stdc++.h>
using namespace std;

struct state {
	pair<int, int> act;
	int pos, par;
	bitset<10> msk;
	state(int ps, int pr, bitset<10> m, pair<int, int> ac) {
		msk = m;
		act = ac;
		pos = ps, par = pr;
	}
};

int r, d, s;
vector<vector<int> > gr, gl;
vector<state> qu;
bool vis[10][1 << 10];

void print(int par) {
	if (par == -1)
		return;
	print(qu[par].par);
	switch (qu[par].act.first) {
	case 1:
		printf("- Move to room %d.\n", qu[par].act.second + 1);
		break;
	case 2:
		printf("- Switch on light in room %d.\n", qu[par].act.second + 1);
		break;
	case 3:
		printf("- Switch off light in room %d.\n", qu[par].act.second + 1);
		break;
	}
}

bool final(const bitset<10> & bs) {
	for (int i = 0; i < r - 1; ++i)
		if (bs[i])
			return 0;
	return bs[r - 1];
}

pair<int, int> BFS(int str, int tar) {
	bitset<10> bs;
	bs.reset();
	bs[0] = 1;
	qu.push_back(state(str, -1, bs, make_pair(-1, -1)));
	int lev = 1;
	size_t pos = 0;
	if (str == tar)
		return make_pair(0, -1);
	while (pos < qu.size()) {
		int siz = qu.size();
		for (size_t i = pos; i < siz; ++i) {
			const state &e = qu[i];
			// move to other room
			for (size_t j = 0; j < gr[e.pos].size(); ++j) {
				int rm = gr[e.pos][j], msk = e.msk.to_ulong();
				if (vis[rm][msk] || !e.msk[rm])
					continue;
				vis[rm][msk] = 1;
				qu.push_back(state(rm, i, e.msk, make_pair(1, rm)));
				if (rm == tar && final(e.msk))
					return make_pair(lev, i);
			}
			// switch a light
			for (size_t j = 0; j < gl[e.pos].size(); ++j) {
				int rm = gl[e.pos][j], msk;
				// open --> close
				if (e.msk[rm]) {
					bitset<10> bs = e.msk;
					bs[rm] = 0;
					msk = bs.to_ulong();
					if (vis[e.pos][msk] || e.pos == rm)
						continue;
					vis[e.pos][msk] = 1;
					qu.push_back(state(e.pos, i, bs, make_pair(3, rm)));
					if (e.pos == tar && final(bs))
						return make_pair(lev, qu.size() - 1);
				} else { // close --> open
					bitset<10> bs = e.msk;
					bs[rm] = 1;
					msk = bs.to_ulong();
					if (vis[e.pos][msk])
						continue;
					vis[e.pos][msk] = 1;
					qu.push_back(state(e.pos, i, bs, make_pair(2, rm)));
					if (e.pos == tar && final(bs))
						return make_pair(lev, qu.size() - 1);
				}
			}
		}
		++lev;
		pos = siz;
	}
	return make_pair(-1, -1);
}

int main(int argc, char **argv) {
	int caseN = 1;
	while (scanf("%d%d%d", &r, &d, &s) > 0 && r + d + s != 0) {
		gr.clear();
		gr.resize(r);
		gl.clear();
		gl.resize(r);
		for (int i = 0; i < d; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			--x, --y;
			gr[x].push_back(y);
			gr[y].push_back(x);
		}
		for (int i = 0; i < s; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			--x, --y;
			gl[x].push_back(y);
		}
		qu.clear();
		memset(vis, false, sizeof vis);
		pair<int, int> res = BFS(0, r - 1);
		printf("Villa #%d\n", caseN++);
		if (res.first != -1) {
			printf("The problem can be solved in %d steps:\n", res.first);
			print(res.second);
		} else
			puts("The problem cannot be solved.");
		putchar('\n');
	}
	return 0;
}
