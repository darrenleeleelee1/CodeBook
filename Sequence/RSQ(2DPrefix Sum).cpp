#include <bits/stdc++.h>
using namespace std;
int arr[110][110];
int query[110][110];
int n;

int main(int argc, char const *argv[])
{
	while(cin >> n){
		// input
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> arr[i][j];
		}
		// bulid prefix query
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				query[i][j] = arr[i][j];
				if(i - 1 >= 0) query[i][j] += query[i-1][j];
				if(j - 1 >= 0) query[i][j] += query[i][j-1];
				if(i - 1 >= 0 && j - 1 >= 0) query[i][j] -= query[i-1][j-1];
			}		
		}

		int temp;
		int maximum = 0x80000000;
		// find the maximum sum in any range  
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = i; k < n; k++){
					for(int t = j; t < n; t++){
						temp = query[k][t];
						if(i - 1 >= 0) temp -= query[i-1][t];
						if(j - 1 >= 0) temp -= query[k][j-1];
						if(i - 1 >= 0 && j - 1 >= 0) temp += query[i-1][j-1];
						if(maximum < temp) maximum = temp;
					}
				}
			}
		}
		printf("%d\n", maximum);


	}
	return 0;
}