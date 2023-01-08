#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
const int maxDigit = 1050;
int unsorted[maxn] = {0, 3, 7, 6, 5}, sorted[maxn], aux[maxDigit];
// aux size is depends on the max digit in sorting
int main(int argc, char const *argv[])
{
	int n = 4;
	// array index start with 1
	memset(aux, 0, sizeof(aux));
	for(int i = 1; i <= n; i++){
		aux[unsorted[i]]++;
	}
	for(int i = 1; i < maxDigit; i++){
		aux[i] += aux[i-1];
	}
	for(int i = n; i > 0; i--){
		sorted[aux[unsorted[i]]] = unsorted[i];
		aux[unsorted[i]]--;
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", sorted[i]);
	}
	return 0;
}