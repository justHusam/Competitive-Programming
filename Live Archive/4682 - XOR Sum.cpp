#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	Node *next[2];
	Node() {
		next[0] = next[1] = NULL;
	}
}*root;

const int N = 1e5, B = 31;
int n, a[N];

void insert(int n) {
	Node *cur = root;
	for (int i = B - 1; i >= 0; --i) {
		int b = (n >> i) & 1;
		if (cur->next[b] == NULL)
			cur->next[b] = new Node();
		cur = cur->next[b];
	}
}

int find(int n) {
	Node *cur = root;
	int res = 0;
	for (int i = B - 1; i >= 0; --i) {
		int b = ((n >> i) & 1) ^ 1;
		if (cur->next[b] != NULL) {
			res += 1 << i;
			cur = cur->next[b];
		} else
			cur = cur->next[b ^ 1];
	}
	return res;
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		root = new Node();
		insert(0);
		int res = 0, w = 0;
		for (int i = 0; i < n; ++i) {
			w ^= a[i];
			insert(w);
			res = max(res, find(w));
		}
		printf("%d\n", res);
	}
	return 0;
}
