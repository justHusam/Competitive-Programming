#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<int> a, vector<int> b) {
	vector<vector<int> > A, B;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	do {
		A.push_back(a);
	} while (next_permutation(a.begin(), a.end()));
	do {
		B.push_back(b);
	} while (next_permutation(b.begin(), b.end()));
	for (vector<int> &x : A)
		for (vector<int> &y : B) {
			int win = 0;
			for (int i = 0; i < 3; ++i)
				if (y[i] > x[i])
					++win;
			if (win < 2)
				return false;
		}
	return true;
}

int main(int argc, char **argv) {
	int p[5];
	while (true) {
		bool vis[53] = { };
		for (int i = 0; i < 5; ++i) {
			scanf("%d", &p[i]);
			vis[p[i]] = true;
		}
		if (p[0] == 0)
			break;
		vector<int> a, b;
		for (int i = 0; i < 3; ++i)
			a.push_back(p[i]);
		for (int i = 3; i < 5; ++i)
			b.push_back(p[i]);
		int res = -1;
		for (int i = 1; i <= 52; ++i) {
			if (vis[i])
				continue;
			b.push_back(i);
			if (check(a, b)) {
				res = i;
				break;
			}
			b.pop_back();
		}
		printf("%d\n", res);
	}
	return 0;
}
