//implement by adjcent list
void dfs(int now, int fa, int layer){
	for (auto j : v[now])
		if(j != fa ) dfs(j, now, layer + 1);
}