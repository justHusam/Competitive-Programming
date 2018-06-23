#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define EPS 1e-9

struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
	inline bool operator ==(point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

inline double cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

inline double dist(const point &p1, const point &p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

inline point toVec(const point &a, const point &b) {
	return point(b.x - a.x, b.y - a.y);
}

inline bool ccw(const point &p, const point &q, const point &r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

inline bool collinear(const point &p, const point &q, const point &r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

point pivot;
inline bool angleCmp(const point &a, const point &b) {
	if (collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> &P) {
	int n = (int) P.size();
	if (n <= 3) {
		if (!(P[0] == P[n - 1]))
			P.push_back(P[0]);
		return P;
	}
	int P0 = 0;
	for (int i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	swap(P[0], P[P0]);
	pivot = P[0];
	sort(++P.begin(), P.end(), angleCmp);
	vector<point> S;
	S.push_back(P[n - 1]);
	S.push_back(P[0]);
	S.push_back(P[1]);
	int i = 2;
	while (i < n) {
		int j = (int) S.size() - 1;
		if (ccw(S[j - 1], S[j], P[i]))
			S.push_back(P[i++]);
		else
			S.pop_back();
	}
	return S;
}

inline double perimeter(const vector<point> &P) {
	double result = dist(P[0], P.back());
	for (int i = 0; i < (int) P.size() - 1; i++)
		result += dist(P[i], P[i + 1]);
	return result;
}

const int N = 15;
int n, v[N], L[N];
point P[N];

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		if (cas != 1)
			puts("");
		for (int i = 0; i < n; ++i)
			scanf("%lf%lf%d%d", &P[i].x, &P[i].y, &v[i], &L[i]);
		vector<point> w;
		int cost = 1e9, sol = -1, ones = 0;
		double ex = 0;
		for (int mask = 0; mask < (1 << n); ++mask) {
			w.clear();
			int out = 0, need = 0, can = 0;
			for (int i = 0; i < n; ++i)
				if (((mask >> i) & 1) == 1) {
					++out;
					can += L[i];
					need += v[i];
				} else
					w.push_back(P[i]);
			if (w.empty() || need > cost || (need == cost && out >= ones))
				continue;
			vector<point> p = CH(w);
			double per = perimeter(p);
			if (per <= can || fabs(per - can) < EPS) {
				sol = mask;
				cost = need;
				ex = can - per;
				ones = w.size();
			}
		}
		printf("Forest %d\nCut these trees:", cas++);
		for (int i = 0; i < n; ++i)
			if (((sol >> i) & 1) == 1)
				printf(" %d", i + 1);
		printf("\nExtra wood: %.2lf\n", ex);
	}
	return 0;
}
