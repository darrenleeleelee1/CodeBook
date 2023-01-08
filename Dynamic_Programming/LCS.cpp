const int maxn = 10000; // maxn is maximum length of arrp and arrq
int arrp[maxn], arrq[maxn];
int dp[maxn+5][maxn+5];
int p, q; // p is the length of arrp, q is the length of arrq
void LCS()
{
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= p; i++){
		for(int j = 1; j <= q; j++){
			if(arrp[i] == arrq[j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}		
	// dp[p][q] is the answer
}