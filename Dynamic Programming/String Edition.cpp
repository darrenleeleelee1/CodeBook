#include <bits/stdc++.h>
using namespace std;
const int maxn = 90;
char s1[maxn], s2[maxn];
int dp[maxn][maxn];
struct Coor
{
	int x, y;
};
Coor backtracking[maxn][maxn];
vector<Coor>ans;
int main(int argc, char const *argv[])
{
	bool begining = true;
	while(gets(s1)){
		gets(s2);
		if(begining) begining = false;
		else printf("\n");
		memset(dp, 0, sizeof(dp));
		memset(backtracking, 0, sizeof(backtracking));
		ans.clear();
		for(int i = 1; i <= strlen(s2); i++) {
			dp[0][i] = dp[0][i-1] + 1;
			backtracking[0][i].x = 0;
			backtracking[0][i].y = i-1;
		}
		for(int i = 1; i <= strlen(s1); i++) {
			dp[i][0] = dp[i-1][0] + 1;
			backtracking[i][0].x = i-1;
			backtracking[i][0].y = 0;
		}
		for(int i = 1; i <= strlen(s1); i++){
			for(int j = 1; j <= strlen(s2); j++){
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
					backtracking[i][j] = Coor{i-1, j-1};
				}
				else{
					dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
					if(dp[i][j] == dp[i][j-1]){
						backtracking[i][j] = Coor{i, j-1};
					}
					else if(dp[i][j] == dp[i-1][j-1]){
						backtracking[i][j] = Coor{i-1, j-1};
					}
					else if(dp[i][j] == dp[i-1][j]){
						backtracking[i][j] = Coor{i-1, j};
					}
					dp[i][j]++;
				}
			}
		}
	
		
		printf("%d\n", dp[strlen(s1)][strlen(s2)]);
		int curi = strlen(s1), curj = strlen(s2);
		ans.push_back(Coor{curi, curj});
		while(curi != 0 || curj != 0){
			int tempi = curi, tempj = curj;
			curi = backtracking[tempi][tempj].x; curj = backtracking[tempi][tempj].y;
			ans.push_back(Coor{curi, curj});
		}
		int offset = 0, cnt = 1;
		for(int i = ans.size()-2; i >= 0; i--){
			if(dp[ans[i].x][ans[i].y] != dp[ans[i+1].x][ans[i+1].y]){
				if((ans[i].x - ans[i+1].x) == 1 && (ans[i].y - ans[i+1].y) == 1){
					printf("%d Replace %d,%c\n", cnt++, ans[i].x + offset, s2[ans[i].y-1]);
				}
				else if((ans[i].x - ans[i+1].x) == 1 && (ans[i].y - ans[i+1].y) == 0){
					printf("%d Delete %d\n", cnt++, ans[i].x+offset);
					offset--;
				}
				else if((ans[i].x - ans[i+1].x) == 0 && (ans[i].y - ans[i+1].y) == 1){
					printf("%d Insert %d,%c\n", cnt++, ans[i].x+offset+1, s2[ans[i].y-1]);
					offset++;
				}
			}
		}
	}
	return 0;
}