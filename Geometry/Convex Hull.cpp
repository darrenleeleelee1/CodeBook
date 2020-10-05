#include <bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
	int d;
}p[600],ch[600];

int dist(point a, point b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}//若點的angle一樣，則比較遠的點

bool find_small_vertex(point a, point b) {
	return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

int cross(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool compare_angle(point a, point b){
	double c = cross( p[0], a, b );
	if ( !c ) return a.d < b.d;
	else return c > 0; 
}

void GrahamScan(int k){
	sort(p+0, p+k, find_small_vertex);
	for(int i=1; i<k; i++){
		p[i].d = dist(p[0], p[i]);
	}
	sort(p+1, p+k, compare_angle);

	int m=0;
	for(int i=0; i<k; i++){
		while(m>=2 && cross(ch[m-2], ch[m-1], p[i]) <= 0){
			m--;
		}
		ch[m++] = p[i];
	}
	// Convex Hull find m nodes and print them out
	printf("%d\n", m+1);
	for(int j=0; j<m; j++){
		printf("%d %d\n", ch[j].x, ch[j].y);
	}
	printf("%d %d\n", ch[0].x, ch[0].y);
}
