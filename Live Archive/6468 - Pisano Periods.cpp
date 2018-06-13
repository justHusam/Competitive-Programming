#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

map<pair<int, int>, int> hs;
queue<int> qu;

int calc(int m) {
	while (!qu.empty())
		qu.pop();
	qu.push(1);
	qu.push(1);
	int id = 2;
	while (true) {
		int x = qu.front();
		qu.pop();
		int y = qu.front();
		++id;
		if (hs.find(make_pair(x, y)) != hs.end())
			return id - hs[make_pair(x, y)];
		hs[make_pair(x, y)] = id;
		int z = x + y;
		z %= m;
		qu.push(z);
	}
	return -1;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int k, m;
		scanf("%d%d", &k, &m);
		hs.clear();
		printf("%d %d\n", k, calc(m));
	}
	return 0;
}
