#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int n, freq[N];

void calc(int n) {
	for (int i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			++freq[i];
			n /= i;
		}
	if (n != 1)
		++freq[n];
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		memset(freq, 0, sizeof freq);
		for (int i = 2; i <= n; ++i)
			calc(i);
		vector<int> v;
		for (int i = 1; i <= n; ++i)
			if (freq[i] != 0)
				v.push_back(freq[i]);
		printf("%3d! =", n);
		int ex = 0;
		for (; n != 0; n /= 10)
			++ex;
		ex += 3 - ex + 3;
		for (size_t i = 0; i < v.size(); ++i) {
			if (i != 0 && i % 15 == 0)
				printf("\n%s", string(ex, ' ').c_str());
			printf("%3d", v[i]);
		}
		puts("");
	}
	return 0;
}
