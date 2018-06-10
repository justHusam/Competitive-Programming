#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
bool isPrime[N], vis[N];
int cost[N];

int calc(int nm, int p, int d) {
	int arr[5], Pow = 1000, res = 0;
	for (int i = 3; i >= 0; i--, nm %= Pow, Pow /= 10) {
		if (i == d)
			arr[i] = p;
		else
			arr[i] = nm / Pow;
	}
	Pow = 1;
	for (int i = 0; i < 4; ++i) {
		res += arr[i] * Pow;
		Pow *= 10;
	}
	return res;
}

int BFS(int src, int dest) {
	queue<int> qu;
	if (src == dest)
		return 0;
	memset(vis, false, sizeof vis);
	qu.push(src);
	vis[src] = true;
	cost[src] = 0;
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 4; ++j) {
				int to = calc(cur, i, j);
				if (to < 10000 && to / 1000 && isPrime[to] && !vis[to]) {
					if (to == dest)
						return cost[cur] + 1;
					vis[to] = true;
					qu.push(to);
					cost[to] = cost[cur] + 1;
				}
			}
	}
	return -1;
}

int main(int argc, char **argv) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i)
		if (isPrime[i])
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int src, dest;
		scanf("%d%d", &src, &dest);
		int res = BFS(src, dest);
		if (res == -1)
			puts("Impossible");
		else
			printf("%d\n", res);
	}
	return 0;
}
