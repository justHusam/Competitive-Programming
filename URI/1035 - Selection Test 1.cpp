#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0)
			puts("Valores aceitos");
		else
			puts("Valores nao aceitos");
	}
    return 0;
}
