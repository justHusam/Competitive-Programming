#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char ch;
	int H, M;
	while (cin >> H >> ch >> M && H + M != 0) {
		double angle = 0.5 * (60 * H - 11 * M);
		if (angle < 0)
			angle *= -1;
		if (angle > 180)
			angle = 360 - angle;
		printf("%.3f\n", angle);
	}
	return 0;
}
