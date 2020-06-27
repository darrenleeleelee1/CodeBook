const int maxn = 60+5;
const int INF = 0x3f3f3f3f;
struct Edge
{
	int from, to, cost;
};
Edge E[maxn * maxn], e[maxn * maxn];
int n, m, c;
int in[maxn], pre[maxn], id[maxn], vis[maxn];
int CLE(int root, int n, int m)
{
	int res = 0;
	while(1)
	{
		for(int i = 0; i < n; i++){
			in[i] = INF;
		}
		//Find in edge
		for(int i = 0; i < m; i++){
			int from = e[i].from, to = e[i].to;
			if(from != to && e[i].cost < in[to]){
				in[to] = e[i].cost;
				pre[to] = from;
			}	
		}
		//Check in edge
		for(int i = 0; i < n; i++){
			if(i == root) continue;
			if(in[i] == INF) return -1;
		}

		int num = 0;
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));
		in[root] = 0;

		//Find cycles
		for(int i = 0; i < n; i++){
			res += in[i];
			int v = i;
			while(vis[v] != i && id[v] == -1 && v != root)
			{
				vis[v] = i;
				v = pre[v];
			}			
			if(v != root && id[v] == -1)
			{
				for(int j = pre[v]; j != v; j = pre[j]){
					id[j] = num;
				}
				id[v] = num++;
			}
		}
		//No cycle
		if(num == 0) break;
		for(int i = 0; i < n; i++){
			if(id[i] == -1) id[i] = num++;
		}
		//Grouping the vertices
		for(int i = 0; i < m; i++){
			int from = e[i].from, to = e[i].to;
			e[i].from = id[from]; e[i].to = id[to];
			if(id[from] != id[to]) e[i].cost -= in[to];
		}
		n = num;
		root = id[root];
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int n, m;
	// n nodes and m edges
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d%d", &E[i].from, &E[i].to, &E[i].cost);
	}
	int sp = 0; // start point
	int ans = CLE(sp, n, m);
	if(ans == -1) printf("No Directed Minimum Spanning Tree.\n");
	else printf("%d\n", ans);
	return 0;
}