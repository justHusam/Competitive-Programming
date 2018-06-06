#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int king() {
	int res = 0;
	int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
	int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && ty > 0 && tx <= n && ty <= n)
			++res;
	}
	return res;
}

int knight() {
	int res = 0;
	int dx[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
	int dy[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && ty > 0 && tx <= n && ty <= n)
			++res;
	}
	return res;
}

int bishop() {
	int res = min(x - 1, y - 1);
	res += min(x - 1, n - y);
	res += min(n - x, y - 1);
	res += min(n - x, n - y);
	return res;
}

int rook() {
	int res = 0;
	res += x - 1;
	res += n - x;
	res += y - 1;
	res += n - y;
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d%d", &n, &x, &y);
	printf("King: %d\n", king());
	printf("Knight: %d\n", knight());
	printf("Bishop: %d\n", bishop());
	printf("Rook: %d\n", rook());
	printf("Queen: %d\n", rook() + bishop());
	return 0;
}
