int maxn = ;
int w[maxn][maxn], dis[maxn];
vector<int> v[maxn];
struct Node
{
	int node, weight;
	Node(int _n, int _w){
		node = _n;
		weight = _w;
	}	
	bool operator<(Node const other)const{
		return weight > other.weight;
	}
};
void dijkstra(int src)
{
	priority_queue<Node> pq;
	pq.push(Node(src, 0));
	while(!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		if(dis[top.node] != 1e9) continue;
		for(auto i : v[top.node]){
			pq.push(Node(i, top.weight + w[top.node][i]));
		}
		dis[top.node] = top.weight;
	}
}