#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<string> a, b;
char s[200];

bool AC() {
	if (n != m)
		return false;
	for (int i = 0; i < n; ++i)
		if (a[i] != b[i])
			return false;
	return true;
}

bool PE() {
	vector<int> v1, v2;
	for (int i = 0; i < n; ++i)
		for (size_t j = 0; j < a[i].size(); ++j)
			if (isdigit(a[i][j]))
				v1.push_back(a[i][j] - '0');
	for (int i = 0; i < m; ++i)
		for (size_t j = 0; j < b[i].size(); ++j)
			if (isdigit(b[i][j]))
				v2.push_back(b[i][j] - '0');
	return v1 == v2;
}

int main(int argc, char **argv) {
	int run = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		a.clear();
		getchar();
		for (int i = 0; i < n; ++i) {
			gets(s);
			a.push_back(s);
		}
		scanf("%d", &m);
		b.clear();
		getchar();
		for (int i = 0; i < m; ++i) {
			gets(s);
			b.push_back(s);
		}
		printf("Run #%d: ", run++);
		if (AC())
			puts("Accepted");
		else if (PE())
			puts("Presentation Error");
		else
			puts("Wrong Answer");
	}
	return 0;
}
