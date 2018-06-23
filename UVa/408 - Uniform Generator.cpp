#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
bool vis[N];

int main(int argc, char **argv) {
	int s, M;
	while (scanf("%d%d", &s, &M) != EOF) {
		for (int i = 0; i < M; ++i)
			vis[i] = false;
		vis[0] = true;
		int at = 0;
		bool can = true;
		for (int i = 1; i < M; ++i) {
			int next = (at + s) % M;
			if (vis[next]) {
				can = false;
				break;
			}
			vis[next] = true;
			at = next;
		}
		printf("%10d%10d    ", s, M);
		if (can)
			puts("Good Choice\n");
		else
			puts("Bad Choice\n");
	}
	return 0;
}
