#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge{
	int u, v, c;
	edge(){}
	edge(int u, int v, int c) :u(u), v(v), c(c){}
};

const int N = 100, oo = 1e9;
int n, m, q, cost[N][N];
vector<edge> e;

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d%d", &n, &m) != EOF){
		for (int i = 0; i < n; ++i){
			fill(cost[i], cost[i] + n, oo);
			cost[i][i] = 0;
		}
		e.clear();
		e.resize(m);
		for (int i = 0; i < m; ++i){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			cost[u][v] = min(cost[u][v], c);
			cost[v][u] = min(cost[v][u], c);
			e[i] = edge(u, v, c);
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
		printf("Set #%d\n", cas++);
		scanf("%d", &q);
		while (q--){
			int src, dest;
			scanf("%d%d", &src, &dest);
			int first = cost[src][dest], second = oo;
			if (first == oo){
				puts("?");
				continue;
			}
			for (int i = 0; i < m; ++i){
				int A = cost[src][e[i].u] + e[i].c + cost[e[i].v][dest];
				int B = cost[src][e[i].v] + e[i].c + cost[e[i].u][dest];
				if (A > first)
					second = min(second, A);
				if (B > first)
					second = min(second, B);
			}
			if (second == oo)
				puts("?");
			else
				printf("%d\n", second);
		}
	}
	return 0;
}