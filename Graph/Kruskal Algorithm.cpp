const int maxn = 1000+5;
struct Edge
{
	int from, to;
	double cost;
	bool operator<(const Edge other){
		return cost < other.cost;
	}
}E[maxn*maxn];
int p[maxn];
vector<Edge> G[maxn];
int find(int x){
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}
bool uni(int x ,int y)
{
	int xRoot = find(x), yRoot = find(y);
	if(xRoot != yRoot){
		if(p[xRoot] < p[yRoot]){
			p[xRoot] += p[yRoot];
			p[yRoot] = xRoot;
		}
		else{
			p[yRoot] += p[xRoot];
			p[xRoot] = yRoot;	
		}
		return true;
	}
	else return false;
}
double kruskal(int n, int m)
{
	// n is the numbers of node, m is the numbers of edge.
	for(int i = 0; i <= n; i++){
		G[i].clear();
		p[i] = -1;
	}
	sort(E, E + m);
	double ans = 0;
	int edge_cnt = 0;
	for(int i = 0; i < m; i++){
		if(uni(E[i].from, E[i].to)){
			int from = E[i].from, to = E[i].to;
			ans += E[i].cost;
			G[from].push_back(Edge{from, to, E[i].cost});
			G[to].push_back(Edge{to, from, E[i].cost});
			if(++edge_cnt == n-1) break;
		}
	}
	if(edge_cnt == n-1) return ans;
	else return -1;// means can't found spanning tree
}
// find max segment in MST graph
int maxcost[maxn][maxn];
vector<int> visited;
void dfs(int pre, int now, int w){
	for(auto x : visited){
		maxcost[x][now] = maxcost[now][x] = max(w, maxcost[pre][x]);
	}
	visited.push_back(now);
	for(auto i : G[now]){
		if(pre != i.to) dfs(now, i.to, i.cost);
	}
}
void findMaxPtah(int sp, int ep){
	memset(maxcost, 0,  sizeof(maxcost));
	visited.clear();
	dfs(-1, sp, 0);
}