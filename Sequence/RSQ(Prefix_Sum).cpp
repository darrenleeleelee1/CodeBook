#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int arr[maxn] = {5, -2, 3, 10, -7, 1, -4, 8, -9};
int query[maxn];
void init()
{
	// every query is the sum of all previos element, include it self
	// example query[3] = arr[0] + arr[1] + arr[2] + arr[3]
	query[0] = arr[0];
	for(int i = 1; i < maxn; i++){
		query[i] = arr[i];
		query[i] += query[i-1];
	}
}
int RangeSumQuery(int s, int e)
{
	//Prefix Sum Algorithm
	if(s >= 1) return query[e] - query[s-1];
	else return query[e];
}
int main(int argc, char const *argv[])
{
	init();
	int start = 2, end = 5;
	printf("RangeSumQuery(%d, %d): %d\n", start, end, RangeSumQuery(start, end));
	
	return 0;
}