queue<int> st;
bool vis[maxn];
memset(vis, false, sizeof(vis));
int src;
st.push(src);
while(!st.empty())
{
	int now = st.front(); st.pop();
    vis[now] = true;
	for(auto i : adj[now])
    	if(!vis[i]) st.push(i);
}