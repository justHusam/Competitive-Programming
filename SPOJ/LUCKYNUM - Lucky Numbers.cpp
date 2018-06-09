#include <bits/stdc++.h>
using namespace std;

struct node {
	int n6, n8, mod;
	bool state;
	node(int n6, int n8, int mod, bool state) :
			n6(n6), n8(n8), mod(mod), state(state) {
	}
};

void print(int n6, int n8) {
	while (n8-- != 0)
		printf("8");
	while (n6-- != 0)
		printf("6");
	puts("");
}

void BFS(int num) {
	queue<node> qu;
	if (6 % num == 0) {
		print(1, 0);
		return;
	}
	if (8 % num == 0) {
		print(0, 1);
		return;
	}
	qu.push(node(1, 0, 6 % num, false));
	qu.push(node(0, 1, 8 % num, true));
	while (!qu.empty()) {
		node T = qu.front();
		qu.pop();
		if (T.n6 + T.n8 == 200)
			continue;
		int mod = (T.mod * 10 + 6) % num;
		if (mod == 0) {
			print(T.n6 + 1, T.n8);
			return;
		}
		qu.push(node(T.n6 + 1, T.n8, mod, false));
		if (T.state) {
			mod = (T.mod * 10 + 8) % num;
			if (mod == 0) {
				print(T.n6, T.n8 + 1);
				return;
			}
			qu.push(node(T.n6, T.n8 + 1, mod, true));
		}
	}
	puts("-1");
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		BFS(n);
	}
	return 0;
}
