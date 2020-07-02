const int maxn = 5000+50;
vector<int> adj[maxn];
stack<int> ans;
int state[maxn];
bool head[maxn];
bool valid;
int n, m;

void dfs(int src)
{
    state[src] = 1;

    for (auto next : adj[src])
        if (!state[next]) dfs(next);
        else if (state[next] == 1){
            // 有環
            valid = false;
            return;
        }

    state[src] = 2;

    ans.push(src);
}

void topology_sort()
{
    for (int i = 0; i < n; i++){
        // 從 (0 ~ n-1) 找一個頭沒有被任何人連到的開始做dfs
        if (valid && head[i]) dfs(i);
    }

    if (!valid)
    {
        cout << "Cycle!" << endl;
        return;
    }

    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
}

int main()
{
    cin >> n >> m;

    memset(head, true, sizeof(head));
    // make adjcent list
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        head[b] = false;
        // 
        adj[a].push_back(b);
    }

    memset(state, 0, sizeof(state));
    valid = true;
    //如果 valid = false代表有還
    topology_sort();

    return 0;
}