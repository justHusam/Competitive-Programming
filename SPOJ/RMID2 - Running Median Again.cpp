#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		priority_queue<int> mn, mx;
		while (scanf("%d", &n) && n > 0) {
			if (n == -1) {
				printf("%d\n", mx.top());
				mx.pop();
				if (mn.size() != mx.size()) {
					mx.push(-mn.top());
					mn.pop();
				}
				continue;
			}
			if (mn.size() == mx.size()) {
				if (!mn.size() || -mn.top() >= n)
					mx.push(n);
				else {
					mx.push(-mn.top());
					mn.pop();
					mn.push(-n);
				}
			} else {
				if (mx.top() > n) {
					mn.push(-mx.top());
					mx.pop();
					mx.push(n);
				} else
					mn.push(-n);
			}
		}
	}
	return 0;
}
