#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n != -1) {
		int sum = 0, moves = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			sum += v[i];
		}
		if (sum % n != 0)
			moves = -1;
		else {
			sum /= n;
			for (size_t i = 0; i < v.size(); i++)
				if (v[i] > sum)
					moves += v[i] - sum;
		}
		printf("%d\n", moves);
	}
	return 0;
}
