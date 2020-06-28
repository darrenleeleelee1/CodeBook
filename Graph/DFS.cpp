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