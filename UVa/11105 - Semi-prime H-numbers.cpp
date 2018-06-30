#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 2;
int n, cum[N];
vector<int> v, H;
bitset<N> bs;
bool ok[N];

int main(int argc, char **argv) {
	for (int i = 0; i * 4 + 1 < N; ++i){
		v.push_back(i * 4 + 1);
		ok[v.back()] = true;
	}
	bs[v[0]] = 1;
	for (int i = 1; i < v.size(); ++i)
		if (!bs[v[i]])
			for (int j = v[i] * 2; j < N; j += v[i])
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (ok[i] && !bs[i])
			H.push_back(i);
	for (int i = 0; i < H.size(); ++i)
		for (int j = i; j < H.size(); ++j){
			ll p = 1LL * H[i] * H[j];
			if (p >= N)
				break;
			if (ok[p])
				cum[p] = 1;
		}
	for (int i = 1; i < N; ++i)
		cum[i] += cum[i - 1];
	int n;
	while (scanf("%d", &n) > 0 && n != 0)
		printf("%d %d\n", n, cum[n]);
	return 0;
}