#include <bits/stdc++.h>
using namespace std;
const int maxn = 7;
// We discard index 0 because building a complete tree is convience
int arr[maxn] = {0, 12, 11, 13, 5, 6, 7};
int heap[maxn];

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
// Check wether the parent node is smaller than its son node
void heapify(int src)
{
	int parent = src;
	while(parent / 2 > 0){
		parent /= 2;
		printf("%d, %d\n", heap[parent], heap[src]);
		if(heap[parent] < heap[src]){
			swap(heap[parent], heap[src]);
			src = parent;
		}
		else break;
	}
}
// Top-down method
void BuildHeap()
{
	for(int i = 1; i < maxn; i++){
		heap[i] = arr[i];
		heapify(i);
	}
}
int main(int argc, char const *argv[])
{
	BuildHeap();
	for (int i = 1; i < maxn; ++i)
	{
		printf("%d ", heap[i]);
	}
	return 0;
}