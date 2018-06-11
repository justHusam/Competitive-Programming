#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	Node *next[2];
	int freq;
	Node() {
		next[0] = next[1] = NULL;
		freq = 0;
	}
}*root;

const int N = 1e5, B = 21;
int n, a[N], k;

void insert(int n) {
	Node *cur = root;
	for (int i = B - 1; i >= 0; --i) {
		int b = (n >> i) & 1;
		if (cur->next[b] == NULL)
			cur->next[b] = new Node();
		cur = cur->next[b];
		++cur->freq;
	}
}

int DFS(Node *cur, int v, int p) {
	if (cur == NULL || p == -1)
		return 0;
	int b = (v >> p) & 1, res = 0;
	if (((k >> p) & 1) == 1) {
		if (cur->next[b] != NULL)
			res += cur->next[b]->freq;
		res += DFS(cur->next[b ^ 1], v, p - 1);
	} else
		res += DFS(cur->next[b], v, p - 1);
	return res;

}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		root = new Node();
		insert(0);
		ll res = 0;
		int w = 0;
		for (int i = 0; i < n; ++i) {
			w ^= a[i];
			res += DFS(root, w, B - 1);
			insert(w);
		}
		printf("%lld\n", res);
	}
	return 0;
}
