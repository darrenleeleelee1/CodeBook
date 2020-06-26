const int n = 6; // number of nodes 
int p[n+10];
void init()
{
	for(int i = 0; i < n; i ++){
		p[i] = -1;
	}
}
int find(int x){
	int root, trail, lead;
	for (root = x ; p[root] >= 0; root = p[root]);
	for (trail = x ; trail! = root; trail=lead) {
        lead = p[trail];
        p[trail]= root;
 	}
 	return root;
}
void uni(int x ,int y)
{
	int xRoot = find(x);
	int yRoot = find(y);
	if(xRoot != yRoot){
		if(p[xRoot] > p[yRoot]){
			p[xRoot] += p[yRoot];
			p[yRoot] = xRoot;
		}
		else{
			p[yRoot] += p[xRoot];
			p[xRoot] = yRoot;	
		}
	}
}
