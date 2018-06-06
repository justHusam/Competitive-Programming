#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	vector<int> x, y;
	int cases, temp, n, min;
	scanf("%d", &cases);
	while (cases-- != 0) {
		int min = 1000000;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp);
			x.push_back(temp);
		}
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp);
			y.push_back(temp);
		}
		for (int i = 0; i < x.size(); i++)
			for (int j = 0; j < y.size(); j++)
				if (abs(x[i] - y[j]) < min)
					min = abs(x[i] - y[j]);
		printf("%d\n", min);
		x.clear();
		y.clear();
	}
	return 0;
}
