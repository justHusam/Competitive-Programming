#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		queue<int> qu;
		for (int i = 1; i <= n; ++i)
			qu.push(i);
		vector<int> res;
		while (qu.size() != 1) {
			res.push_back(qu.front());
			qu.pop();
			qu.push(qu.front());
			qu.pop();
		}
		printf("Discarded cards:");
		string s = " ";
		for (size_t i = 0; i < res.size(); ++i, s = ", ")
			printf("%s%d", s.c_str(), res[i]);
		printf("\nRemaining card: %d\n", qu.front());
	}
	return 0;
}
