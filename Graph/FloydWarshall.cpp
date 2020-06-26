//dis[i][j] is the distance of node i to node j
int dis[n+5][n+5];
void init()
{
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 0; i < n; i++) d[i][i] = 0;
}
void floyd(){
	for (int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dis[i][j] = dis[j][i] = min(dis[i][j],  dis[i][k] + dis[k][j]);	
}
int main(int argc, char const *argv[])
{
	//If we got n nodes, label from 0 to (n-1)
	init();
	//Set the dis
	floyd();	
}