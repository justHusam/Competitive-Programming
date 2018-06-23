#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int Pow(ll a, ll b, int M) {
	if (b == 0)
		return 1;
	ll res = Pow(a, b >> 1, M);
	res = (res * res) % M;
	if ((b & 1) == 1)
		res = (res * a) % M;
	return res;
}

int main(int argc, char **argv) {
	int B, P, M;
	while (scanf("%d%d%d", &B, &P, &M) != EOF)
		printf("%d\n", Pow(B, P, M));
	return 0;
}
