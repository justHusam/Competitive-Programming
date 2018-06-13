#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001;
bitset<N> bs;
vector<int> p;

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (!bs[i])
			p.push_back(i);
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		vector<int> sol;
		for (int i = 1; i <= n; ++i)
			if (bs[i] == 0) {
				int rem = n - i;
				for (int j = 1; j <= rem; ++j)
					if (bs[j] == 0 && bs[rem - j] == 0) {
						sol.push_back(i);
						sol.push_back(j);
						sol.push_back(rem - j);
						sort(sol.begin(), sol.end());
						break;
					}
				if (!sol.empty())
					break;
			}
		if (sol.empty())
			puts("0");
		else
			printf("%d %d %d\n", sol[0], sol[1], sol[2]);
	}
	return 0;
}
