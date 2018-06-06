#include <bits/stdc++.h>
using namespace std;

char line[105];
int cases, len;

int main() {
	scanf("%d", &cases);
	while (cases-- != 0) {
		getchar();
		scanf("%[^\n]", line);
		len = strlen(line);
		reverse(line, line + len / 2);
		reverse(line + len / 2, line + len);
		puts(line);
	}
	return 0;
}
