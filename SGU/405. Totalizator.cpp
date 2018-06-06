#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, res[100];

int calc(pair<int, int>&a, pair<int, int>&b) {
	int res = 0;
	if (a.first == a.second && b.first == b.second)
		res += 2;
	else if (a.first > a.second && b.first > b.second)
		res += 2;
	else if (a.second > a.first && b.second > b.first)
		res += 2;
	if (a.first - a.second == b.first - b.second)
		res += 3;
	if (a.first == b.first)
		++res;
	if (a.second == b.second)
		++res;
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	pair<int, int> a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a.first, &a.second);
		for (int j = 0; j < n; ++j) {
			scanf("%d%d", &b.first, &b.second);
			res[j] += calc(a, b);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%s%d", i ? " " : "", res[i]);
	puts("");
	return 0;
}
