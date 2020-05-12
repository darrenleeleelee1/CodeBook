#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int from, to, weight;
	bool operator< (const Edge other) const{
		return weight < other.weight;
	}
};
int n, m; // n is number of nodes, m is number of edges
Edge edge[25000+10];
int parent[1000+10];
void init()
{
	for(int i = 0; i < n; i ++){
		parent[i] = -1;
	}
}
int find(int x)
{
	int xParent = x;
	while(parent[xParent] >= 0){
		xParent = parent[xParent];
	}
	return xParent;
}
bool connect(int x ,int y)
{
	int xParent = find(x);
	int yParent = find(y);
	if(xParent != yParent){
		parent[xParent] = yParent;
		return true;
	}
	else return false;
}
int main(int argc, char const *argv[])
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		for(int i = 0; i < m; i++){
			cin >> edge[i].from >> edge[i].to >> edge[i].weight;
		}
		init();
		sort(edge, edge + m); // Kruskal need to sort the edge by thier weight
		int minCost = 0; // minimum spanning tree cost
		for(int i = 0; i < m; i++){
			if(connect(edge[i].from, edge[i].to)){ 
				minCost += edge[i].weight;
			}
		}
		printf("%d\n", minCost);
	}
	return 0;
}