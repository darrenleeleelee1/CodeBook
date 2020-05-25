#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
vector<int> ans;
vector<int> adj[maxn];
int refs[maxn];
int n = 5;

// refs 紀錄這個點被幾個邊連到
void TopologyOrder()
{
	for(int i = 0; i < n; i++){
		int s = 0;
		while(s < n && refs[s] != 0) {
			s++;
		}
		if(s == n) break;
		refs[s] = -1;
		ans.push_back(s);
		for(auto j : adj[s]){
			refs[j]--;
		}
	}
}
int main(int argc, char const *argv[])
{	
	memset(refs, 0, sizeof(refs));
	ans.clear();
	// adj[from].push_back(to); refs[to]++;
	adj[4].push_back(1); refs[1]++;
	adj[1].push_back(3); refs[3]++;
	adj[1].push_back(0); refs[0]++;
	adj[2].push_back(0); refs[0]++;
	adj[3].push_back(0); refs[0]++;
	TopologyOrder();
	for(int i = 0; i < ans.size(); i++){
		if(i == ans.size()-1) printf("%d\n", ans[i]);
		else printf("%d ", ans[i]);
	}
	return 0;
}