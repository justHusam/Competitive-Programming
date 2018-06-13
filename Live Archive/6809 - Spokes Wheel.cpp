#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[111];

ll decimal() {
	ll res = 0, p = 1;
	int n = strlen(s);
	for (int i = n - 1; i >= 0; --i) {
		ll v;
		if (isdigit(s[i]))
			v = s[i] - '0';
		else
			v = s[i] - 'A' + 10;
		res += v * p;
		p *= 16;
	}
	return res;
}

deque<int> binary(ll n) {
	deque<int> qu;
	for (; n; n >>= 1)
		qu.push_front(n & 1);
	return qu;
}

inline bool check(deque<int> A, ll B) {
	ll res = 0, p = 1;
	while (!A.empty()) {
		ll bc = A.back();
		A.pop_back();
		res += bc * p;
		p <<= 1;
	}
	return res == B;
}

int calcL(deque<int> A, ll B) {
	if (check(A, B))
		return 0;
	for (int i = 0; i < 50; ++i) {
		int fr = A.front();
		A.pop_front();
		A.push_back(fr);
		if (check(A, B))
			return i + 1;
	}
	return -1;
}

int calcR(deque<int> A, ll B) {
	if (check(A, B))
		return 0;
	for (int i = 0; i < 50; ++i) {
		int bc = A.back();
		A.pop_back();
		A.push_front(bc);
		if (check(A, B))
			return i + 1;
	}
	return -1;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		deque<int> A = binary(decimal());
		scanf("%s", s);
		ll B = decimal();
		while (A.size() < 32)
			A.push_front(0);
		int L = calcL(A, B);
		int R = calcR(A, B);
		printf("Case #%d: ", cas++);
		if (L == -1 && R == -1)
			puts("Not possible");
		else if (L == -1 || R < L)
			printf("%d Right\n", R);
		else if (R == -1 || L < R)
			printf("%d Left\n", L);
		else
			printf("%d Any\n", L);
	}
	return 0;
}
