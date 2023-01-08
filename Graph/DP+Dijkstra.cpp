#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+10;
int n, m, u, v, d, c, s, e, Q;
int cost[maxn];
int weight[maxn][maxn];
vector<int> adj[maxn];
int dp[maxn][100+10];
struct Car
{
	int cur, left, costSum;
	bool operator<(const Car &other)const{
		return costSum > other.costSum;
	}
};
int dij()
{
	if(s == e) return 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= c; j++)
			dp[i][j] = 1e9;
	priority_queue<Car> pq;
	pq.push(Car{s, 0, 0});
	while(!pq.empty()){
		auto top = pq.top();  pq.pop();	
		if(dp[top.cur][top.left] < top.costSum) continue;
		if(top.cur == e && top.left == 0) return dp[top.cur][top.left];
		for(auto i : adj[top.cur]){
			if(c < weight[top.cur][i]) continue;
			for(int j = top.left; j <= c; j++){
				if(j < weight[top.cur][i]) continue;
				int OilCost = cost[top.cur] * (j - top.left);
				int temp = j - weight[top.cur][i]; 
				if(dp[i][temp] > top.costSum + OilCost){
					dp[i][temp] = top.costSum + OilCost;
					pq.push(Car{i, j - weight[top.cur][i], dp[i][temp]});
				}
			}
		}
	}
	return 1e9;

}
int main(int argc, char const *argv[])
{
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i = 0; i < n; i++){
			adj[i].clear();
			scanf("%d", &cost[i]);
		}
		for(int i = 0;  i < m; i++){
			scanf("%d%d%d", &u, &v, &d);
			adj[u].push_back(v);
			adj[v].push_back(u);
			weight[u][v] = d;
			weight[v][u] = d;
		}
		scanf("%d", &Q);
		while(Q--){
			scanf("%d%d%d", &c, &s, &e);
			int res = dij();
			if(res == 1e9) printf("impossible\n");
			else printf("%d\n", res);
		}

	}
	return 0;
}