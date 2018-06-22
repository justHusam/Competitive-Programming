#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int v[3][3];
string prt[] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

inline int calc(int i) {
	int res = 0;
	for (int i = 0; i < 3; ++i)
		if (prt[i][i] == 'B') {
			for (int j = 0; j < 3; ++j)
				if (i != j)
					res += v[j][0];
		} else if (prt[i][i] == 'G') {
			for (int j = 0; j < 3; ++j)
				if (i != j)
					res += v[j][1];
		} else if (prt[i][i] == 'C') {
			for (int j = 0; j < 3; ++j)
				if (i != j)
					res += v[j][2];
		}
	return res;
}

int main(int argc, char **argv) {
	while (scanf("%d", &v[0][0]) > 0) {
		for (int i = 0; i < 3; ++i)
			for (int j = i ? 0 : 1; j < 3; ++j)
				scanf("%d", &v[i][j]);
		int res = 2e9, idx = -1;
		for (int i = 0; i < 6; ++i) {
			int temp = calc(i);
			if (temp < res)
				res = temp, idx = i;
		}
		printf("%s %d\n", prt[idx].c_str(), res);
	}
	return 0;
}
