#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int r, c, k;
string g[100], v[100];

inline int check() {
	int cnt = 0;
	for (int i = 0; i < r; ++i)
		if (g[i] == v[i])
			++cnt;
	if (cnt == r)
		return 1;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (v[i][j] != '*' && g[i][j] != v[i][j])
				return 0;
	return 2;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &r, &c, &k);
		for (int i = 0; i < r; ++i)
			cin >> g[i];
		int y = 0, x = 0;
		while (k-- != 0) {
			for (int i = 0; i < r; ++i)
				cin >> v[i];
			int temp = check();
			if (temp == 1)
				++x;
			if (temp == 2)
				++y;
		}
		if (x != 0 || y == 1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
