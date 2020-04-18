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
// Button-up method
void BuildHeap()
{
	for(int i = maxn - 1; i > 0; i--){
		int index = i;
		while(index / 2 > 0){
			if(arr[index/2] > arr[index]){
				swap(arr[index/2], arr[index]);
				index /= 2;
			}
			else break;
		}
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