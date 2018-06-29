#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

char g[5][5];
pair<int, int> v[5];
int id, vis[5][5];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
set<string> st;

inline bool check(char ch) {
	if (ch == 'A' || ch == 'O' || ch == 'E' || ch == 'I' || ch == 'U' || ch == 'Y')
		return 1;
	return 0;
}

inline void calc(int ID) {
	if (ID == 3) {
		++id;
		int cnt = 0;
		string s = "";
		for (int i = 0; i < 4; ++i) {
			if (vis[v[i].first][v[i].second] == id)
				return;
			vis[v[i].first][v[i].second] = id;
			cnt += check(g[v[i].first][v[i].second]);
			s += g[v[i].first][v[i].second];
		}
		if (cnt == 2)
			st.insert(s);
		return;
	}
	for (int i = 0; i < 8; ++i) {
		int tx = v[ID].first + dx[i];
		int ty = v[ID].second + dy[i];
		if (tx < 0 || ty < 0 || tx >= 4 || ty >= 4)
			continue;
		v[ID + 1] = make_pair(tx, ty);
		calc(ID + 1);
	}
}

int main(int argc, char **argv) {
	char x[5][5], y[5][5];
	bool newLine = false;
	while (scanf(" %c", &x[0][0]) > 0 && x[0][0] != '#') {
		if (newLine)
			puts("");
		newLine = true;
		for (int i = 0; i < 4; ++i) {
			for (int j = i ? 0 : 1; j < 4; ++j)
				scanf(" %c", &x[i][j]);
			for (int j = 0; j < 4; ++j)
				scanf(" %c", &y[i][j]);
		}
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				g[i][j] = x[i][j];
		st.clear();
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				v[0] = make_pair(i, j);
				calc(0);
			}
		set<string> temp = st;
		st.clear();
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				g[i][j] = y[i][j];
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				v[0] = make_pair(i, j);
				calc(0);
			}
		vector<string> res;
		set<string>::iterator it;
		for (it = st.begin(); it != st.end(); ++it)
			if (temp.find(*it) != temp.end())
				res.push_back(*it);
		if (res.empty())
			puts("There are no common words for this pair of boggle boards.");
		else {
			for (size_t i = 0; i < res.size(); ++i)
				puts(res[i].c_str());
		}
	}
	return 0;
}
