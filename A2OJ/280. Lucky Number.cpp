#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		char s1[10], s2[10];
		scanf("%s%s", s1, s2);
		int p1[] = { 0, 1, 2, 3, 4, 5, 6 };
		int n1 = strlen(s1), n2 = strlen(s2);
		vector<int> x, y;
		do {
			int n = 0;
			if (s1[p1[0]] == '0')
				continue;
			for (int i = 0; i < n1; ++i)
				n = n * 10 + (s1[p1[i]] - '0');
			x.push_back(n);
		} while (next_permutation(p1, p1 + n1));
		int p2[] = { 0, 1, 2, 3, 4, 5, 6 };
		do {
			int n = 0;
			if (s2[p2[0]] == '0')
				continue;
			for (int i = 0; i < n2; ++i)
				n = n * 10 + (s2[p2[i]] - '0');
			y.push_back(n);
		} while (next_permutation(p2, p2 + n2));
		bool res = false;
		for (size_t i = 0; i < x.size() && !res; ++i)
			for (size_t j = 0; j < y.size(); ++j) {
				int n = x[i] + y[j], c = 0, temp = 1;
				while (n != 0 && temp != 0) {
					++c;
					int a = n % 10;
					n /= 10;
					if (n == 0)
						temp = 0;
					else {
						int b = n % 10;
						n /= 10;
						if (a != b)
							temp = 0;
					}
				}
				if (temp != 0) {
					res = true;
					break;
				}
			}
		if (res)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
