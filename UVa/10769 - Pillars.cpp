#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int H, n, m, v[100], g[100];
char s[1111];

int main(int argc, char **argv) {
	while (scanf("%d", &H) > 0) {
		n = m = 0;
		getchar();
		gets(s);
		for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
			v[n++] = atoi(z);
		gets(s);
		for (char *z = strtok(s, " "); z != NULL; z = strtok(NULL, " "))
			g[m++] = atoi(z);
		sort(v, v + n);
		sort(g, g + m);
		reverse(v, v + n);
		reverse(g, g + m);
		map<int, vector<int> > x, y;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				int sum = v[i] + v[j];
				vector<int> temp;
				temp.push_back(v[i]);
				temp.push_back(v[j]);
				if (x.find(sum) == x.end())
					x[sum] = temp;
				else
					x[sum] = max(x[sum], temp);
			}
		for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < m; ++j) {
				int sum = g[i] + g[j];
				vector<int> temp;
				temp.push_back(g[i]);
				temp.push_back(g[j]);
				if (y.find(sum) == y.end())
					y[sum] = temp;
				else
					y[sum] = max(y[sum], temp);
			}
		vector<int> res;
		map<int, vector<int> >::iterator it;
		for (it = x.begin(); it != x.end(); ++it) {
			if (y.find(H - it->first) == y.end())
				continue;
			vector<int> v;
			v.push_back(it->second[0]);
			v.push_back(y[H - it->first][0]);
			v.push_back(it->second[1]);
			v.push_back(y[H - it->first][1]);
			if (res.empty())
				res = v;
			else
				res = max(res, v);
		}
		if (res.empty())
			puts("no solution");
		else {
			for (int i = 0; i < 4; ++i)
				printf("%s%d", i ? " " : "", res[i]);
			puts("");
		}
	}
	return 0;
}
