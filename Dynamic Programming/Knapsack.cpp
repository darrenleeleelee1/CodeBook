#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int track[1005][1005];
struct Item{
	int value, weight;
};
vector <Item> item;
int main(){
	int n, W, t, t1, t2, temp_w, temp_v;
	vector <int> ans_item;
	cin >> n;
	while(n--){
		cin >> W >> t;//W = total weight, t = # of item
		item.clear(); ans_item.clear();
		item.push_back(Item{0, 0});
		for(int i = 0 ; i<t ; i++){
			cin >> t1 >> t2;
			item.push_back(Item{t1, t2});
		}
		memset(track, 0, sizeof(track));
		for(int i = 0 ; i<=t ; i++){//row - i
			temp_w = item[i].weight;
			temp_v = item[i].value;
			for(int w = 0 ; w<=W ; w++){
				if(i == 0 || w == 0){
					dp[w][i] = 0;
					continue;
				}
				if(temp_w <= w){
					//dp[w][i] = max(dp[w][i-1], dp[w - temp_w][i-1] + temp_v);
					if((dp[w - temp_w][i-1] + temp_v) > dp[w][i-1]){
						dp[w][i] = dp[w - temp_w][i-1] + temp_v;
						track[w][i] = true;//true=有放
					}
					else{
						dp[w][i] = dp[w][i-1];
					}
				}
				else{
					dp[w][i] = dp[w][i-1];
				}
			}
		}
		cout << dp[W][t] << endl;
		//backtracking
		int ii = t-1, ww = W;
		while(ii != 0){
			if(track[ww][ii]){
				ww -= item[ii].weight;
				ans_item.push_back(ii);
			}
			ii -= 1;
		}
	}
}