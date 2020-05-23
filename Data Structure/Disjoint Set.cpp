#include <bits/stdc++.h>
using namespace std;
const int n = 6; // number of nodes 
int parent[n+10];
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
void unions(int x ,int y)
{
	int xParent = find(x);
	int yParent = find(y);
	if(xParent != yParent){
		if(parent[xParent] > parent[yParent]){
			parent[xParent] += parent[yParent];
			parent[yParent] = xParent;
		}
		else{
			parent[yParent] += parent[xParent];
			parent[xParent] = yParent;	
		}
	}
}
