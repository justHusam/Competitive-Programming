#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
int n;
char s[N][N];
string p[] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };

int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	int d = (n / 16 + 1) * 16;
	for (int i = 0; i < d; ++i)
		printf("%s: %s\n", s[i % n], p[i % 16].c_str());
	return 0;
}
