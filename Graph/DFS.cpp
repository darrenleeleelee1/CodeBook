//implement by adjcent list
//functional dfs
void dfs(int now, int fa, int layer){
	for (auto j : adj[now])
		if(j != fa ) dfs(j, now, layer + 1);
}
//stack dfs
stack<int> st;
bool vis[maxn]; 
memset(vis, false, sizeof(vis));
int src;
st.push(src);
while(!st.empty())
{
	int now = st.top(); st.pop();
    vis[now] = true;
    for(auto i : adj[now])
    	if(!vis[i]) st.push(i);	
}
//DFS with Discover time and Finish time
const int maxn = 10;
struct Node{
	int d, f, color;
	// d: discover time, f: finish time, color: 0 == white, 1 == gray, 2 == black  
	/*
	Topology sort by finsih time, Larger out first
	bool operator< (const Node other) const{
		return color > other.color;
	}
	*/
};
vector<int> adj[maxn];
Node node[maxn];
int times;
void DFS(int src)
{
	node[src].d = times++;
	node[src].color = 1;
	for(auto i : adj[src]){
		if(node[i].color == 0) DFS(i);
	}
	node[src].color = 2;
	node[src].f = times++;
}
void DFS_Start(int n, int sp)
{
	for(int i = 0; i < n; i++){
		node[i].color = 0;
	}
	times = 0;
	DFS(sp);

}
int main(int argc, char const *argv[])
{
	int n, m, x, y;
	cin >> n >> m;
	for(int i = 0; i < n; i++) adj[i].clear();
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	DFS_Start(6, 0);
	for(int i = 0; i < n; i++){
		printf("%d: d: %d f: %d color: %d\n", i, node[i].d, node[i].f, node[i].color);
	}
	//sort(node, node + n); print out is the order of topology order
	return 0;
}