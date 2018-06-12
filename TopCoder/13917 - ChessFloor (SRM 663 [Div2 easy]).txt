#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class ChessFloor {
public:
	vector<string> g;
	int n;

	int minimumChanges(vector<string> floor) {
		g = floor;
		n = g.size();
		int res = 2e9;
		for (char i = 'a'; i <= 'z'; ++i)
			for (char j = 'a'; j <= 'z'; ++j)
				if (i != j)
					res = min(res, calc(i, j));
		return res;
	}

	int calc(char a, char b) {
		vector<char> x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i % 2 == 0 && j % 2 == 0)
					x.push_back(g[i][j]);
				else if (i % 2 == 1 && j % 2 == 1)
					x.push_back(g[i][j]);
				else
					y.push_back(g[i][j]);
		int res = 0;
		for (size_t i = 0; i < x.size(); ++i)
			if (x[i] != a)
				++res;
		for (size_t i = 0; i < y.size(); ++i)
			if (y[i] != b)
				++res;
		return res;
	}
};
