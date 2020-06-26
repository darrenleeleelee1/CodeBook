const int maxn = 500+10;
bool visit[maxn];
int primes[maxn];
int sieve(int src)
{
	memset(visit, false, sizeof(visit));
	for(int i = 2; i <= sqrt(src + 0.5); i++){
		if(!visit[i]){
			for(int j = i * i; j <= src; j += i){
				visit[j] = true;
			}
		}
	}
	int cnt = 0;
	for(int i = 2; i <= src; i++){
		if(!visit[i]) primes[cnt++] = i;
	}
	return cnt;
}