#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	int at, type, H, M;
	state(int at, int type, int H, int M) :
			at(at), type(type), H(H), M(M) {
	}
	bool operator<(const state &e) const {
		if (e.H != H)
			return H < e.H;
		if (e.M != M)
			return M < e.M;
		return e.type < type;
	}
};

int ex, sz[2];
vector<state> v;
queue<pair<int, int> > qu[2];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &ex, &sz[0], &sz[1]);
		v.clear();
		for (int i = 0; i < 2; ++i)
			for (int j = 0, H, M; j < sz[i]; ++j)
				for (int it = 0; it < 2; ++it) {
					scanf("%d:%d", &H, &M);
					v.push_back(state(i, it, H, M));
				}
		sort(v.begin(), v.end());
		for (int i = 0; i < 2; ++i)
			while (!qu[i].empty())
				qu[i].pop();
		int need[] = { 0, 0 };
		for (size_t i = 0; i < v.size(); ++i) {
			int at = v[i].at;
			if (v[i].type == 1) {
				int H = v[i].H;
				int M = v[i].M;
				M += ex;
				if (M >= 60) {
					++H;
					M %= 60;
				}
				if (H < 24)
					qu[at ^ 1].push(make_pair(H, M));
				continue;
			}
			if (!qu[at].empty() && (qu[at].front().first < v[i].H || (qu[at].front().first == v[i].H && qu[at].front().second <= v[i].M)))
				qu[at].pop();
			else
				++need[at];
		}
		printf("Case #%d: %d %d\n", cas++, need[0], need[1]);
	}
	return 0;
}
