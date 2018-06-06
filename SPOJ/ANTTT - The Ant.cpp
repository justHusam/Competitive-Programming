#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

const int N = 1e3;
int n, q, p[N];
pair<point, point> v[N];

bool onSegment(point p, point q, point r) {
	int mx1 = max(p.x, r.x), mx2 = max(p.y, r.y);
	int mn1 = min(p.x, r.x), mn2 = min(p.y, r.y);
	return q.x <= mx1 && q.x >= mn1 && q.y <= mx2 && q.y >= mn2;
}

int orientation(point p, point q, point r) {
	int v = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (v == 0)
		return 0;
	if (v > 0)
		return 1;
	return 2;
}

bool doIntersect(point p1, point q1, point p2, point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return true;
	if (o1 == 0 && onSegment(p1, p2, q1))
		return true;
	if (o2 == 0 && onSegment(p1, q2, q1))
		return true;
	if (o3 == 0 && onSegment(p2, p1, q2))
		return true;
	if (o4 == 0 && onSegment(p2, q1, q2))
		return true;
	return false;
}

int find(int v) {
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d%d", &v[i].first.x, &v[i].first.y, &v[i].second.x, &v[i].second.y);
		for (int i = 0; i < n; ++i)
			p[i] = i;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (doIntersect(v[i].first, v[i].second, v[j].first, v[j].second))
					p[find(i)] = find(j);
		while (q-- != 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			a = find(a - 1);
			b = find(b - 1);
			if (a == b)
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
