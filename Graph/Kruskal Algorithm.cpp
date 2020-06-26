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
	int xRoot = x;
	while(p[xRoot] >= 0){
		xRoot = p[xRoot];
	}
	return xRoot;
}
bool uni(int x, int y){
	int xRoot = find(x), yRoot = find(y);
	if(xRoot == yRoot) return false;
	else{
		p[yRoot] = xRoot;
		return true;
	}
}
double kruskal(int n, int m)
{
	// n is the numbers of node, m is the numbers of edge.
	for(int i = 0; i < n; i++){
		G[i].clear();
		p[i] = -1;
	}
	sort(E, E + m);
	double ans = 0;
	for(int i = 0; i < m; i++){
		if(uni(E[i].from, E[i].to)){
			int from = E[i].from, to = E[i].to;
			ans += E[i].cost;
			G[from].push_back(Edge{from, to, E[i].cost});
			G[to].push_back(Edge{to, from, E[i].cost});
		}
	}
	return ans;
}
