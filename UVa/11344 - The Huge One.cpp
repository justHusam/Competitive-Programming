#include <bits/stdc++.h>
using namespace std;

char s[1111];
vector<int> v;
int n;

bool check() {
	vector<int> mod(n, 0);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < n; ++j)
			mod[j] = (mod[j] * 10 + (s[i] - '0')) % v[j];
	for (int i = 0; i < n; ++i)
		if (mod[i])
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%d", s, &n);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		printf("%s - ", s);
		if (check())
			puts("Wonderful.");
		else
			puts("Simple.");
	}
	return 0;
}
