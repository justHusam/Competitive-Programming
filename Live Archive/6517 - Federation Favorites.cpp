#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0) {
		if (n == -1)
			break;
		vector<int> v;
		ll sum = 0;
		for (int i = 1; i < n; ++i)
			if (n % i == 0) {
				v.push_back(i);
				sum += i;
			}
		if (sum == n) {
			printf("%d", n);
			string s = " = ";
			for (size_t a = 0; a < v.size(); ++a, s = " + ")
				printf("%s%d", s.c_str(), v[a]);
			puts("");
			continue;
		}
		printf("%d is NOT perfect.\n", n);
	}
	return 0;
}
