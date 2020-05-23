#include <bits/stdc++.h>
using namespace std;
const int n = 8;
int B[n] = {18, 17, 13, 19, 15, 11, 20, 87};
typedef vector<int> vi;
vi A (B, B + 8);
vi ST;
void ST_Build(vi &ST, const vi &A, int vertex, int L, int R)
{
	if(L == R) ST[vertex] = L;
	else
	{
		int nL = vertex * 2, nR = vertex * 2 + 1;
		ST_Build(ST, A, nL, L, L + (R - L) / 2);
		ST_Build(ST, A, nR, L + (R - L) / 2 + 1, R);
		int indexL = ST[nL], indexR = ST[nR];
		int valueL = A[indexL], valueR = A[indexR];
		ST[vertex] = valueL <= valueR ? indexL : indexR;
	}
}

void ST_Creation(vi &ST, const vi &A)
{
	int len = 4 * A.size();
	ST.assign(len, 0);
	ST_Build(ST, A, 1, 0, A.size()-1);
}
int query(vi &ST, const vi &A, int vertex, int L, int R, int qL, int qR)
{
	int temp, mid = (L + R) / 2;
	if(qL <= L && R <= qR) return ST[vertex];
	if(qR <= mid)
	{
		return query(ST, A, vertex * 2, L, mid, qL, qR);
	}
	if(qL > mid)
	{
		return query(ST, A, vertex * 2 + 1, mid + 1, R, qL, qR);
	}
	return A[query(ST, A, vertex * 2, L, mid, qL, qR)] <= A[query(ST, A, vertex * 2 + 1, mid + 1, R, qL, qR)]
			? query(ST, A, vertex * 2, L, mid, qL, qR) : query(ST, A, vertex * 2 + 1, mid + 1, R, qL, qR);

}
void update(vi &ST, vi &A, int x, int L, int R, int p,int v)
{
	// p is the index where you want to update
	// v is the value will be update in A[p];
	int mid = L + (R - L) / 2;
	if(L == R) A[ST[x]] = v;
	else
	{
		if(p <= mid) update(ST, A, x*2, L, mid, p, v);
		else update(ST, A, x*2+1, mid+1, R, p, v);
		ST[x] = (A[ST[x*2]] <= A[ST[x*2+1]]) ? ST[x*2] : ST[x*2+1];
	}
}
int main(int argc, char const *argv[])
{
	ST_Creation(ST, A);
	printf("%d\n", query(ST, A, 1, 0, n-1, 3, 7));
	// query return the index
	printf("%d\n", A[query(ST, A, 1, 0, n-1, 3, 7)]);
	update(ST, A, 1, 0, n-1, 5, 18);
	// query and update first to fifth parameter dont change
	// ST, A, 1, 0, n-1
	// last two would be 
	// query: the range(array index) you want to query
	// update: fisrt is the index you want to update, second is the value will be
	return 0;
}