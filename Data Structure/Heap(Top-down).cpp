#include <bits/stdc++.h>
using namespace std;
const int maxn = 7;
// We discard index 0 because building a complete tree is convience
int arr[maxn] = {0, 12, 11, 13, 5, 6, 7};

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
// Check wether the parent node is smaller than its son node
void heapify(int parent)
{
	int largest = parent;
	int left = parent * 2;
	int right = parent * 2 + 1;
	if(left < maxn && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < maxn && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != parent){
			swap(arr[parent], arr[largest]);
			// Because we just swap the value, we need to
			// Check after we swap the value the smaller one is also bigger than its child
			heapify(largest);
	}

}
// Top-down method
void BuildHeap()
{
	for(int i = maxn / 2; i > 0; i--){
		heapify(i);
	}
}
int main(int argc, char const *argv[])
{
	BuildHeap();
	for (int i = 1; i < maxn; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}