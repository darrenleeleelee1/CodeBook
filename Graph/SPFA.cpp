#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f;
const int maxn = 10000+5;

int n, m;
int dist[maxn], vis[maxn], out[maxn];
vector<pair<int, int>> adj[maxn];

void init()
{
	memset(dist, INF, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	memset(out, 0, sizeof(out));
	for(int i = 0; i <= n;  i++){
		adj[i].clear();
	}
}

bool spfa(int sp, int n)
{
	queue<int> q;
	q.push(sp);

	while(!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0;
		out[u]++;
		if(out[u] > n) return false; // negative cycle occurs

		for(int j = 0; j < adj[u].size(); j++){
			int v = adj[u][j].first;
			if(dist[v] > dist[u] + adj[u][j].second){
				dist[v] = dist[u] + adj[u][j].second;
				if(vis[v]) continue;

				vis[v] = 1;
				q.push(v);
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// n nodes and m edges
	scanf("%d%d", &n, &m);
	init();	
	// make adjcent list
	int a, b, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &w);
		adj[a].push_back(make_pair(b, w));
	}
	int sp = 0; // start point
	dist[sp] = 0; vis[sp] = 1;
	if(spfa(sp, n)) printf("%d\n", dist[n-1]);
	else printf("can't reach.\n");
	return 0;
}