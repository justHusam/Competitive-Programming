#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, v[2];
	scanf("%d%d%d", &n, &v[0], &v[1]);
	priority_queue<pair<int, int> > qu;
	qu.push(make_pair(-v[0], 0));
	qu.push(make_pair(-v[1], 1));
	int w = 0, mx = 0;
	while (!qu.empty()) {
		pair<int, int> a = qu.top();
		qu.pop();
		a.first *= -1;
		if (qu.empty()) {
			++w;
			mx = max(mx, a.first);
			if (w < n) {
				a.first = -(a.first + v[a.second]);
				qu.push(a);
			}
			continue;
		}
		pair<int, int> b = qu.top();
		qu.pop();
		b.first *= -1;
		if (a.first == b.first) {
			w += 2;
			mx = max(mx, a.first);
			if (w < n) {
				a.first = -(a.first + v[a.second]);
				b.first = -(b.first + v[b.second]);
				qu.push(a);
				qu.push(b);
			}
			continue;
		}
		b.first *= -1;
		qu.push(b);
		++w;
		mx = max(mx, a.first);
		if (w < n) {
			a.first = -(a.first + v[a.second]);
			qu.push(a);
		}
	}
	printf("%d %d\n", w, mx);
	return 0;
}
