#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 1;
bitset<N> bs;
vector<int> all;
map<int, int> vis;
int vs;

bool check(int n) {
	if (vis[n] == vs)
		return false;
	vis[n] = vs;
	if (n == 1)
		return true;
	int temp = 0;
	while (n != 0) {
		int m = n % 10;
		n /= 10;
		temp += m * m;
	}
	return check(temp);
}

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 2; i < N; ++i)
		if (bs[i] == 0) {
			++vs;
			if (check(i))
				all.push_back(i);
		}
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int cas, n;
		scanf("%d%d", &cas, &n);
		printf("%d %d ", cas, n);
		if (binary_search(all.begin(), all.end(), n))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
