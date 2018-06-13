#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int S, R, x, y;

int main(int argc, char **argv) {
	while (scanf("%d%d", &S, &R) && S + R > 0) {
		v.resize(S + 2);
		for (int i = 1; i <= S; ++i) {
			v[i].first = i - 1;
			v[i].second = i + 1;
		}
		v[S].second = 0;
		for (int i = 1; i <= R; ++i) {
			scanf("%d%d", &x, &y);
			v[v[x].first].second = v[y].second; // ok
			v[v[y].second].first = v[x].first;  // ok
			if (v[x].first != 0)
				printf("%d ", v[x].first);
			else
				printf("* ");
			if (v[y].second != 0)
				printf("%d\n", v[y].second);
			else
				printf("*\n");
		}
		printf("-\n");
		v.clear();
	}
	return 0;
}
