#include<bits/stdc++.h>
using namespace std;

struct state {
	int s, e, k;
} arr[2][100];

const int N = 1e6;
int n, m, vis[1000001], id;

bool check() {
	if (n == 1 && m == 0)
		return true;
	if (m == 1 && n == 0)
		return arr[1][0].e - arr[1][0].s <= arr[1][0].k;
	for (int i = 0; i < n; ++i)
		for (int j = arr[0][i].s; j < arr[0][i].e; ++j) {
			if (vis[j] == id)
				return false;
			vis[j] = id;
		}
	for (int i = 0; i < m; ++i)
		for (int j = arr[1][i].s; j < arr[1][i].e; ++j) {
			if (vis[j] == id)
				return false;
			vis[j] = id;
		}
	for (int i = 0; i < m; ++i)
		for (int j = 1;; ++j) {
			int s = arr[1][i].s + arr[1][i].k * j, e = min(arr[1][i].e + arr[1][i].k * j, N);
			if (s > N)
				break;
			while (s < e) {
				if (vis[s] == id)
					return false;
				vis[s++] = id;
			}
		}
	return true;
}

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && n + m != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &arr[0][i].s, &arr[0][i].e);
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &arr[1][i].s, &arr[1][i].e, &arr[1][i].k);
		++id;
		if (check())
			puts("NO CONFLICT");
		else
			puts("CONFLICT");
	}
	return 0;
}
