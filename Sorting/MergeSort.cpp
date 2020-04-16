#include <bits/stdc++.h>
using namespace std;
int maxn = 10;
int arr[maxn] = {5, 2, 6, 8, 1, 3, 4, 9, 10, 7};
void Merge(int left, int mid, int right){
	vector<int> leftArr, rightArr;
	for(int i = left; i <= right; i++){
		if(i <= mid){
			leftArr.push_back(arr[i]);
		}
		else{
			rightArr.push_back(arr[i]);
		}
	}
	leftArr.push_back(1e9);
	rightArr.push_back(1e9);
	int indexl = 0, indexr = 0;
	for(int i = left; i <= right; i++){
		if(leftArr[indexl] < rightArr[indexr]){
			arr[i] = leftArr[indexl++];
		}
		else{
			arr[i] = rightArr[indexr++];
		}
	}

}
void mergeSort(int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

int main(int argc, char const *argv[])
{
	mergeSort(0, maxn-1);
	for(int i = 0; i < maxn; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}