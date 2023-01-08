#include <bits/stdc++.h>
using namespace std;
struct node
{
	int val, layer;
};
int visit[1000+5];
int isPrime[1000];

node BFS(int src, int des)
{
	queue<node> q;
	q.push(node{src, 0});
	memset(visit, 0, sizeof(visit));
	visit[src] = 0;
	while(!q.empty()){
		auto front = q.front();
		if(front.val == des) break;
		q.pop();
		if(front.val > des) continue;
		for(int i = 2; i < front.val; i++){
			if(isPrime[i] && front.val % i == 0 && visit[front.val + i] <= front.layer) {
				q.push(node{front.val + i, front.layer + 1});
				visit[front.val + i] = front.layer + 1;
			}
		}
	}
	if(!q.empty()) return q.front();
	else return node{-1, -1};
}
int main(int argc, char const *argv[])
{
	int s, t, ctr = 0;
	for(int i = 2; i <= 1000; i++){
		bool ok = true;
		for(int j = 2; j <= sqrt(i); j++){
			if(i % j == 0) ok = false;
		}
		if(ok) isPrime[i] = true;
		else isPrime[i] = false;
	}
	int cas = 1;
	while(scanf("%d%d", &s, &t))
	{
		if(s == 0 && t == 0) break;
		node ans = BFS(s, t);
		printf("Case %d: %d\n", cas++, ans.layer);
	}
	return 0;
}