#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 8;
int n, a[N], b[N], p[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

bool check(double mid){
	double at = a[p[0]];
	for (int i = 1; i < n; ++i){
		at = max(1.0 * a[p[i]], at + mid);
		if (at <= b[p[i]])
			continue;
		return false;
	}
	return true;
}

double BS(){
	double l = 0, r = 90000, res = 0;
	for (int it = 0; it < 32; ++it){
		double mid = (l + r) / 2;
		if (check(mid)){
			res = mid;
			l = mid;
		} else
			r = mid;
	}
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0){
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &a[i], &b[i]);
			a[i] *= 60;
			b[i] *= 60;
		}
		sort(p, p + n);
		double res = 0;
		do{
			res = max(res, BS());
		} while (next_permutation(p, p + n));
		res = int(res + 0.5);
		printf("Case %d: %d:%02d\n", cas++, int(res / 60), (int)res % 60);
	}
	return 0;
}