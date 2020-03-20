int main(int argc, char const *argv[])
{
	//initialize dis[] with 1e9
	//make an adjecnt list
	call bellman_ford(src);
	return 0;
}

void bellman_ford(int src)
{
	dis[src] = 0;									//initialize source with distance 0	
	for (int k = 0; k < n - 1; ++k){				//do n-1 times
	 	for (int i = 0; i < n; ++i){
	 		for(auto j : v[i]){
	 			if(dis[i] != 1e9) dis[j] = min(dis[j], dis[i] + w[i][j]);
	 		}
	 	}
	 } 
}
bool negativeCycle()
{
	for(i = 0; i < n; ++i){
		for(auto j : v[i]){
			if(dis[j] > dis[i] + w[i][j]) return true //has negative cycle
		}
	}
	return false;
}