#include <bits/stdc++.h>
using namespace std;
const int n = 16; 
int arr[n] = {13, -3, -25, 20, -3, -16, -23,
				18, 20, -7, 12, -5, -22, 15, -4, 7};

int findMaxCrosing(int left, int mid, int right){
	int maxl = 0x80000000;
	int sum = 0;
	for(int i = mid; i >= left; i--){
		sum += arr[i];
		if(sum > maxl) maxl = sum;
	}
	int maxr = 0x80000000;
	sum = 0;
	for(int i = mid + 1; i <= right; i++){
		sum += arr[i];
		if(sum > maxr) maxr = sum;
	}

	return (maxl + maxr);
}

int findMaxSub(int left, int right)
{
	if(left == right){
		return arr[left];
	}
	else{
		int mid = left + (right - left) / 2;
		int maxl = findMaxSub(left, mid);
		int maxr = findMaxSub(mid + 1, right);
		int res = max(maxl, maxr);
		res = max(res, findMaxCrosing(left, mid, right));
		return res;	
	}
}


int main(int argc, char const *argv[])
{
	printf("%d\n", findMaxSub(0, n-1));
	return 0;
}