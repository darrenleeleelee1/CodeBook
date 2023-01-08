#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
const int maxw = 1e5+5;
long long dp[maxw];
int main(int argc, char const *argv[])
{
	int n, w;
	scanf("%d%d", &n, &w);
	
	memset(dp, 0, sizeof dp);
	int x, v;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &x, &v);
		for(int j = w; j >= x; j--){
			dp[j] = max(dp[j], dp[j-x] + v);
		}
	}

	printf("%lld\n", dp[w]);
	return 0;
}