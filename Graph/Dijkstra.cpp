#define PII pair<int, int>
#define maxn 50000+5

int dis[maxn]; // 預設都是 INF
vector<PII> adj[maxn]; // (連到的點,邊的距離)

void dijk(int src) // dijk(起點)
{ 
  priority_queue<PII,vector<PII>,greater<PII>> q; // 放(點編號,距離)，每次會拿距離最小的點出來
  q.push(make_pair(src, 0));
    
  	while (!q.empty()) 
  	{
    	auto top = q.top(); q.pop();
  		printf("%d %d\n", top.first, top.second);
    	if (dis[top.first] != 1e9) continue; // 如果之前就拜訪過就continue
   
    	dis[top.first] = top.second;
    	for (auto i: adj[top.first]){
        	if (dis[i.first] == 1e9) q.push(make_pair(i.first, i.second + top.second));     		
    	}
    }
}

void init(void)
{
    fill(dis, dis+maxn, 1e9);

    for(int i = 0; i < maxn; i++){
        adj[i].clear();
    }
}

int main(int argc, char const *argv[])
{
	init();
	// make adjcnet list
	int sp = 0; // start point
	dijk(sp);
	// dis[x] store the distance from sp to x
	return 0;
}