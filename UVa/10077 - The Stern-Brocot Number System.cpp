#include<bits/stdc++.h>
using namespace std;

struct state {
	double x, y;
	state() {
	}
	state(double x, double y) :
			x(x), y(y) {
	}
} e;

string calc(state l, state r) {
	state n = state(l.x + r.x, l.y + r.y);
	if (n.x == e.x && n.y == e.y)
		return "";
	double a = n.x / n.y;
	double b = e.x / e.y;
	if (b < a)
		return 'L' + calc(l, n);
	return 'R' + calc(n, r);
}

int main(int argc, char **argv) {
	while (scanf("%lf%lf", &e.x, &e.y) > 0) {
		if (e.x == 1 && e.y == 1)
			break;
		cout << calc(state(0, 1), state(1, 0)) << "\n";
	}
	return 0;
}
