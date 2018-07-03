#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

struct team {
	char name[35];
	int points, wins, ties, loses, games, diff, scored, against;
	team() {
		points = wins = ties = loses = games = diff = scored = against = 0;
	}
	void update(int s, int a) {
		++games;
		scored += s;
		against += a;
		diff = scored - against;
		if (s > a) {
			++wins;
			points += 3;
			return;
		}
		if (s == a) {
			++ties;
			++points;
			return;
		}
		++loses;
	}
	bool operator<(const team&e) const {
		if (e.points != points)
			return e.points < points;
		if (e.wins != wins)
			return e.wins < wins;
		if (e.diff != diff)
			return e.diff < diff;
		if (e.scored != scored)
			return e.scored < scored;
		if (e.games != games)
			return e.games > games;
		return strcasecmp(name, e.name) < 0;
	}
};

int main(int argc, char **argv) {
	int T;
	scanf("%d\n", &T);
	while (T-- != 0) {
		char nm[105];
		gets(nm);
		int n;
		scanf("%d\n", &n);
		vector<team> v(n);
		map<string, int> hs;
		for (int i = 0; i < n; ++i) {
			gets(v[i].name);
			hs[v[i].name] = i;
		}
		int g;
		scanf("%d\n", &g);
		while (g-- != 0) {
			char s[1000];
			gets(s);
			int idx, g1 = 0, g2 = 0;
			string s1, s2;
			for (idx = 0; s[idx] != '#'; ++idx)
				s1 += s[idx];
			for (++idx; s[idx] != '@'; ++idx)
				g1 = g1 * 10 + (s[idx] - '0');
			for (++idx; s[idx] != '#'; ++idx)
				g2 = g2 * 10 + (s[idx] - '0');
			for (++idx; s[idx]; ++idx)
				s2 += s[idx];
			int i1 = hs[s1], i2 = hs[s2];
			v[i1].update(g1, g2);
			v[i2].update(g2, g1);
		}
		sort(v.begin(), v.end());
		puts(nm);
		for (int i = 0; i < n; ++i) {
			printf("%d) %s %d", i + 1, v[i].name, v[i].points);
			printf("p, %d", v[i].games);
			printf("g (%d-%d-%d), %d", v[i].wins, v[i].ties, v[i].loses, v[i].diff);
			printf("gd (%d-%d)\n", v[i].scored, v[i].against);
		}
		if (T != 0)
			puts("");
	}
	return 0;
}
