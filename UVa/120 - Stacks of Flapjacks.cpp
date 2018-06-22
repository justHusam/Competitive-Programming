#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 30;
char s[5555];
int n, v[N], p[N], all[N], pos[101];
vector<int> res;

int main(int argc, char **argv) {
	while (gets(s) > 0) {
		n = 0;
		for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "), ++n)
			v[n] = p[n] = all[n] = atoi(z);
		sort(all, all + n);
		for (int i = 0; i < n; ++i)
			pos[all[i]] = i;
		reverse(all, all + n);
		res.clear();
		for (int i = 0, r = n; i < n; ++i, --r) {
			int idx = -1;
			for (int j = 0; idx == -1; ++j)
				if (all[i] == v[j])
					idx = j;
			if (idx == pos[all[i]])
				continue;
			if (idx != 0) {
				res.push_back(n - idx);
				reverse(v, v + idx + 1);
			}
			reverse(v, v + r);
			res.push_back(i + 1);
		}
		printf("%d", p[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", p[i]);
		puts("");
		for (size_t a = 0; a < res.size(); ++a)
			printf("%d ", res[a]);
		puts("0");
	}
	return 0;
}
