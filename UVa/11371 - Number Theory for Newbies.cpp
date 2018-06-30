#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int x;
	while (scanf("%d", &x) > 0) {
		int freq[10] = { }, mn = 2e9;
		for (; x; x /= 10) {
			++freq[x % 10];
			if (x % 10 != 0)
				mn = min(mn, x % 10);
		}
		string s, p;
		s += mn + '0';
		--freq[mn];
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < freq[i]; ++j)
				s += i + '0';
		p = s;
		sort(p.rbegin(), p.rend());
		long long a = atoll(p.c_str()), b = atoll(s.c_str()), def = a - b;
		printf("%lld - %lld = %lld = 9 * %lld\n", a, b, def, def / 9);
	}
	return 0;
}
