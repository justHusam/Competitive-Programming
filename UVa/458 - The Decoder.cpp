#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	char ch;
	while (scanf(" %c", &ch) > 0) {
		if (ch == '\n')
			puts("");
		else
			printf("%c", ch - 7);
	}
	return 0;
}
