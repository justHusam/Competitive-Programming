#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, int> a, b;
char s[20];
int n;

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		a.clear();
		b.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			++a[s];
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			++b[s];
		}
		map<string, int>::iterator it;
		int res = 0;
		for (it = a.begin(); it != a.end(); ++it)
			res += min(it->second, b[it->first]);
		printf("%d\n", res);
	}
	return 0;
}
