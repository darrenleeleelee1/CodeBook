#include <bits/stdc++.h>
using namespace std;
int n, gift[100000+10], L, R;
int leftn[100000+10], rightn[100000+10];
bool ok(int src)
{
	int l = gift[0], r = src - gift[0];
	leftn[0] = gift[0], rightn[0] = 0;
	for(int i = 1; i < n; i++)
	{
		if(i % 2 == 1){
			leftn[i] = min(l - leftn[i-1], gift[i]);
			rightn[i] = gift[i] - leftn[i];
		}
		else{
			rightn[i] = min(r - rightn[i-1], gift[i]);
			leftn[i] = gift[i] - rightn[i];
		}
	}
	return leftn[n-1] == 0;
}
int main(int argc, char const *argv[])
{
	while(cin >> n && n){
		L = R = 0;
		for(int i = 0; i < n; i++){
			cin >> gift[i];
		}
		
		if(n == 1) {
			printf("%d\n", gift[0]);
			continue;
		}
		
		
		gift[n] = gift[0];
		for(int i = 1; i <= n; i++){
			L = max(L, gift[i-1] + gift[i]);
		}
		if(n % 2 == 0){
			printf("%d\n", L);
		}
		else{
			for(int i = 0; i < n; i++){
				R = max(R, 3 * gift[i]);
			}
			while(L < R){
				int M = L + (R - L) / 2;
				if(ok(M)) R = M;
				else L = M + 1;
			}
			printf("%d\n", R);
		}
	}
	return 0;
}