#include <bits/stdc++.h>
using namespace std;

int calc(int n) {
	vector<int> v;
	int x = 0, y = 0;
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end());
	for (size_t i = 0, j = v.size() - 1; i < v.size(); ++i, --j) {
		x += v[i] * pow(10, j);
		y += v[i] * pow(10, i);
	}
	printf("%d - %d = %d\n", y, x, y - x);
	return y - x;
}

int main(int argc, char **argv) {
	set<int> st;
	int N, M;
	while (scanf("%d", &N) && N != 0) {
		M = 0;
		printf("Original number was %d\n", N);
		N = calc(N);
		st.insert(N);
		++M;
		while (true) {
			N = calc(N);
			++M;
			if (st.find(N) != st.end())
				break;
			st.insert(N);
		}
		printf("Chain length %d\n\n", M);
		st.clear();
	}
	return 0;
}
