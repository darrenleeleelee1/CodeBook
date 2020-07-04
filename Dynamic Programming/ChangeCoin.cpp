#include<bits/stdc++.h>
using namespace std;
long long dp[30005][5];
int cents[5] = {1, 5, 10, 25, 50};
int main(){
	long long N, ans;
	while(cin >> N){
		for(int k = 0 ; k<5 ; k++){
			for(int n = 0 ; n<=N ; n++){
				if(k == 0 || n == 0){
					dp[n][k] = 1;
					continue;
				}
				if(n < cents[k]){
					dp[n][k] = dp[n][k-1];
				}
				else dp[n][k] = dp[n][k-1] + dp[n - cents[k]][k];
			}
		}
		ans = dp[N][4];
		printf("There are %lld ways to produce %lld cents change.\n", ans, N);

	}
}