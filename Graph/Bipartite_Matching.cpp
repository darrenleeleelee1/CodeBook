const int maxn = 500+5;
int W[maxn][maxn], n;
int Lx[maxn], Ly[maxn];
int Lef[maxn];
bool S[maxn], T[maxn];
bool match(int i)
{
	S[i] = true;
	for (int j = 1; j <= n; ++j)
	{
		if(Lx[i] + Ly[j] == W[i][j] && !T[j])
		{
			T[j] = true;
			if(!Lef[j] || match(Lef[j]))
			{
				Lef[j] = i;

				return true;
			}
		}
	}
	return false;
}
void update()
{
	int a = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
	{
		if(S[i])
		{
			for(int j = 1; j <= n; j++)
			{
				if(!T[j]) a = min(a, Lx[i] + Ly[j] - W[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(S[i]) Lx[i] -= a;
		if(T[i]) Ly[i] += a;
	}
}
void KM()
{
	for (int i = 1; i <= n; ++i)
	{
		Lef[i] = Lx[i] = Ly[i] = 0;
		for(int j = 1; j <= n; j++){
			Lx[i] = max(Lx[i], W[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for(;;){
			for(int j = 1; j <= n; j++){
				S[j] = T[j] = 0;
			}
			if(match(i)) break;
			else update();
		}
			
		
	}
}
int main(int argc, char const *argv[])
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &W[i][j]);
		}
	}
	
	KM();	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		ans += Ly[i];
		ans += Lx[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(i != n) printf("%d ", Lx[i]);
		else printf("%d\n", Lx[i]);
	}
	
	for(int i = 1; i <= n; i++){
		if(i != n) printf("%d ", Ly[i]);
		else printf("%d\n", Ly[i]);
	}

	printf("%d\n", ans);	
	return 0;
}