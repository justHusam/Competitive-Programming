#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int R[3][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } }, C[3][3] = { { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 } };
pair<int, char> rA[3] = { make_pair(1, 'H'), make_pair(2, 'H'), make_pair(3, 'H') };
pair<int, char> cA[3] = { make_pair(1, 'V'), make_pair(2, 'V'), make_pair(3, 'V') };

inline void horizontal(vector<int>&v, int r) {
	int x = v[R[r][0]];
	int y = v[R[r][1]];
	int z = v[R[r][2]];
	v[R[r][0]] = y;
	v[R[r][1]] = z;
	v[R[r][2]] = x;
}

inline void RH(vector<int>&v, int r) {
	int x = v[R[r][0]];
	int y = v[R[r][1]];
	int z = v[R[r][2]];
	v[R[r][0]] = z;
	v[R[r][1]] = x;
	v[R[r][2]] = y;
}

inline void vertical(vector<int>&v, int c) {
	int x = v[C[c][0]];
	int y = v[C[c][1]];
	int z = v[C[c][2]];
	v[C[c][0]] = z;
	v[C[c][1]] = x;
	v[C[c][2]] = y;
}

inline void RV(vector<int>&v, int c) {
	int x = v[C[c][0]];
	int y = v[C[c][1]];
	int z = v[C[c][2]];
	v[C[c][0]] = y;
	v[C[c][1]] = z;
	v[C[c][2]] = x;
}

struct state {
	pair<int, char> ac;
	vector<int> p;
	int lev;
	state() {
	}
	state(const pair<int, char>&ac, const vector<int>&p, int lev) :
			ac(ac), p(p), lev(lev) {
	}
};

map<vector<int>, state> cum;

inline void BFS() {
	vector<int> str;
	for (int a = 1; a < 10; ++a)
		str.push_back(a);
	cum[str] = state(make_pair(-1, '?'), vector<int>(), 0);
	queue<vector<int> > qu;
	qu.push(str);
	int lev = 1;
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz-- != 0) {
			vector<int> temp = qu.front(), fr = qu.front();
			qu.pop();
			for (int i = 0; i < 3; ++i) {
				horizontal(fr, i);
				if (cum.find(fr) == cum.end()) {
					cum[fr] = state(rA[i], temp, lev);
					qu.push(fr);
				}
				RH(fr, i);
			}
			for (int i = 0; i < 3; ++i) {
				vertical(fr, i);
				if (cum.find(fr) == cum.end()) {
					cum[fr] = state(cA[i], temp, lev);
					qu.push(fr);
				}
				RV(fr, i);
			}
		}
		++lev;
	}
}

int main(int argc, char **argv) {
	BFS();
	vector<int> v(9);
	while (scanf("%d", &v[0]) > 0 && v[0] != 0) {
		for (int i = 1; i < 9; ++i)
			scanf("%d", &v[i]);
		if (cum.find(v) == cum.end()) {
			puts("Not solvable");
			continue;
		}
		printf("%d ", cum[v].lev);
		for (state e = cum[v]; e.ac.first != -1; e = cum[e.p])
			printf("%c%d", e.ac.second, e.ac.first);
		puts("");
	}
	return 0;
}
