#include<bits/stdc++.h>
using namespace std;

const int N = 2e6;
char s[N];
int arr[1000];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, res = 2e9, id = 0;
		scanf("%d", &n);
		getchar();
		for (int i = 1; i <= n; ++i) {
			gets(s);
			int temp = 0;
			for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
				++temp;
			if (temp < res)
				res = temp, id = 0;
			if (temp == res)
				arr[id++] = i;
		}
		printf("%d", arr[0]);
		for (int i = 1; i < id; ++i)
			printf(" %d", arr[i]);
		puts("");
	}
	return 0;
}
