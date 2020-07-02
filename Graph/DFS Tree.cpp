#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
vector<int> adj[maxn];
int blocks[maxn];
void dfs(int cur, int fa)
{
	blocks[cur] = 1;
	for(auto i : adj[cur]){
		if(i != fa) {
			dfs(i, cur);
			blocks[cur] += blocks[i];
		}
	}
}
int main(int argc, char const *argv[])
{
	int n, x;
	while(cin >> n){
		for(int i = 0; i <= n; i++) adj[i].clear();
		memset(blocks, 0, sizeof(blocks));
		// blocks 為包含自己，自己的子節點數量
		// 建一個無環的圖
		for(int i = 1; i < n; i++){
			cin >> x;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
		// 從0當Root做dfs
		dfs(0, -1);
		for(int i = 0; i < n; i++) {
			int ans = 0;
			for(auto j : adj[i]){
				if(blocks[i] > blocks[j]) ans = max(ans, blocks[j]);
			}
			ans = max(ans, n - blocks[i]);
			printf("%d\n", ans);
		}

	}
	return 0;
}