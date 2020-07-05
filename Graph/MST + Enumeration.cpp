#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
struct Edge
{
	int from, to, cost;
	bool operator<(const Edge other){
		return cost < other.cost;
	}
}E[maxn*maxn];
int p[maxn];
int find(int x){
	int root, trail, lead;
	for (root = x ; p[root] >= 0; root = p[root]);
	for (trail = x ; trail != root; trail = lead) {
        lead = p[trail];
        p[trail]= root;
 	}
 	return root;
}
bool uni(int x ,int y)
{
	int xRoot = find(x), yRoot = find(y);
	if(xRoot != yRoot){
		if(p[xRoot] > p[yRoot]){
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
int kruskal(int n, int m)
{
	// n is the numbers of node, m is the numbers of edge.
	for(int i = 0; i <= n; i++){
		p[i] = -1;
	}
	sort(E, E + m);
	int maxedge, minedge, difference = 1e9;
	for(int k = 0; k <= m - n + 1; k++){
		maxedge = -1; minedge = 1e9;
		memset(p, -1, sizeof(p));
		int cnt = 0;
		for(int i = k; i < m; i++){
			if(uni(E[i].from, E[i].to)){
				int from = E[i].from, to = E[i].to;
				minedge = min(minedge, E[i].cost);
				maxedge = max(maxedge, E[i].cost);
				cnt++;
			}
		}
		if(cnt == n-1){
			if(maxedge - minedge < difference){
				difference = maxedge - minedge;
			}	
		}
		
	}
	return difference;
}
int main(int argc, char const *argv[])
{
	int n, m;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		for(int i = 0; i < m; i++){
			cin >> E[i].from >> E[i].to >> E[i].cost;
		}
		if(m < n-1) printf("-1\n");
		else{
			int mincost = kruskal(n, m);
			if(mincost == 1e9) printf("-1\n");
			else printf("%d\n", mincost);
		}
	}
	return 0;
}