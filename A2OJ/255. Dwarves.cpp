#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int v[10];
		for (int i = 0; i < 9; ++i)
			scanf("%d", v + i);
		vector<int> g;
		for (int i = 0; i < 9; ++i)
			g.push_back(i);
		do {
			int sum = 0;
			for (int i = 0; i < 7; ++i)
				sum += v[g[i]];
			if (sum == 100)
				break;
		} while (next_permutation(g.begin(), g.end()));
		for (int i = 0; i < 7; ++i)
			printf("%d\n", v[g[i]]);
	}
	return 0;
}
