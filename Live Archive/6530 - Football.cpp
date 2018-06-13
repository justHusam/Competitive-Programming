#include <bits/stdc++.h>
using namespace std;

struct state {
	int need, points, ini;
	state(int need, int points, int ini) :
			need(need), points(points), ini(ini) {
	}
	bool operator<(const state&e) const {
		if (e.need != need)
			return e.need < need;
		int d1 = points - ini;
		int d2 = e.points - e.ini;
		return d2 > d1;
	}
};

int main(int argc, char **argv) {
	int n, can;
	while (scanf("%d%d", &n, &can) > 0) {
		int sum = 0;
		priority_queue<state> qu;
		while (n--) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a > b)
				sum += 3;
			else if (a == b) {
				++sum;
				qu.push(state(1, 3, 1));
			} else
				qu.push(state(b - a, 1, 0));
		}
		while (!qu.empty()) {
			state e = qu.top();
			qu.pop();
			if (e.need > can)
				break;
			can -= e.need;
			sum -= e.ini;
			sum += e.points;
			if (e.points == 1)
				qu.push(state(1, 3, 1));
		}
		printf("%d\n", sum);
	}
	return 0;
}
