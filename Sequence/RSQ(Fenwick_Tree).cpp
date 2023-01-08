#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int arr[maxn] = {5, -2, 3, 10, -7, 1, -4, 8, -9};
int FenwickTree[maxn];
int ANDlowbit(int src)
{
	// src & -src will get the lowbit
	// example: 6 & -6 = 0110 & 1010 = 0010 = 2 
	return src & -src;
}
void init()
{
	
	memset(FenwickTree, 0, sizeof(FenwickTree));
	// Notice that we start in 1
	for(int i = 1; i <= maxn; i++){
		int index = i;
		FenwickTree[i] += arr[i-1];
		int temp = arr[i-1];
		while(index + ANDlowbit(index) <= maxn){
			index += ANDlowbit(index);
			FenwickTree[index] += temp;
		}
	}
}
void Modify(int src, int val)
{
	// Modify arr[src] to val
	int gap = val - arr[src];
	arr[src] = val;
	int index = src + 1;
	FenwickTree[index] += gap;
	while(index + ANDlowbit(index) <= maxn){
		index += ANDlowbit(index);
		FenwickTree[index] += gap;
	}
}
int SequenceQuery(int src)
{
	//src is the index of the array which we want to know the Sequence Query
	int res = FenwickTree[src];
	int index = src;
	while(index - ANDlowbit(index) > 0){
		index -= ANDlowbit(index);
		res += FenwickTree[index];
	}
	return res;
}
int RangeSumQuery(int s, int e)
{
	return SequenceQuery(e) - SequenceQuery(s - 1);
}
int main(int argc, char const *argv[])
{
	init();
	int start = 2, end = 5;
	// for Fenwick index is 3, 6 for array index is 2, 5
	printf("RangeSumQuery(%d, %d): %d\n", start, end, RangeSumQuery(start + 1, end + 1));
	Modify(2, 5);
	// Modify arr[2] from 3 to 5
	printf("RangeSumQuery(%d, %d): %d\n", start, end, RangeSumQuery(start + 1, end + 1));
	return 0;
}