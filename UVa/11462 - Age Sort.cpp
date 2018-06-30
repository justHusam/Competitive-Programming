#include<bits/stdc++.h>
using namespace std;

inline int readchar() {
	const int N = 1048576;
	static char buf[N];
	static char *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, N, stdin)) == buf)
			return EOF;
		p = buf;
	}
	return *p++;
}

inline bool geti(int *x) {
	static char c, neg;
	while ((c = readchar()) < '-')
		if (c == EOF)
			return false;
	neg = (c == '-') ? -1 : 1;
	*x = (neg == 1) ? c - '0' : 0;
	while ((c = readchar()) >= '0')
		*x = (*x << 3) + (*x << 1) + c - '0';
	*x *= neg;
	return true;
}

void puti(int n) {
	int idx = 0;
	char arr[15];
	if (n < 0)
		putchar('-'), n *= -1;
	for (; n; n /= 10)
		arr[idx++] = n % 10 + '0';
	while (idx > 0)
		putchar(arr[--idx]);
}

int f[101], vis[101], id;

int main(int argc, char **argv) {
	int n;
	while (geti(&n) && n != 0) {
		++id;
		for (int i = 0, x; i < n; ++i) {
			geti(&x);
			if (vis[x] != id)
				vis[x] = id, f[x] = 0;
			++f[x];
			vis[x] = id;
		}
		for (int i = 1; i <= 100 && n != 0; ++i)
			for (int j = 0; j < f[i]; ++j) {
				puti(i);
				if (--n != 0)
					putchar(' ');
			}
		putchar('\n');
	}
	return 0;
}
