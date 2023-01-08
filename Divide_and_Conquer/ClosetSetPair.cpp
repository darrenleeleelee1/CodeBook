struct point2D
{
	double x, y;
	bool operator< (point2D const other) const{
		return x < other.x;
	}
	bool operator> (point2D const other) const{
		return y > other.y;
	}
};
point2D p[10000+10];

double dis(point2D p1, point2D p2)
{
	return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}
double bruteforce(int start, int n){
	double mind = 2e9;
	for(int i = start; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			mind = min(mind, dis(p[i], p[j]));
		}
	}
	return mind;
}
double findcp(int left, int right,int n)
{
	if(n <= 3){
		return bruteforce(left, n);
	}
	double mind;
	int mid = left + (right - left) / 2;
	double cl = findcp(left, mid, mid - left + 1);
	double cr = findcp(mid + 1, right, right - mid);
	mind = min(cl, cr);
	vector<point2D> v;
	for(int i = left; i <= right; i++){
		if(p[i].x <= p[mid].x + mind && p[i].x >= p[mid].x - mind)
			v.push_back(p[i]);
	}
	sort(v.begin(), v.end(), greater<point2D>());

	for(vector<point2D>::iterator it = v.begin(); it != v.end()-1; it++){
		for(vector<point2D>::iterator jt = it + 1; jt != v.end(); jt++){
			mind = min(mind, dis(*it, *jt));
		}
	}
	return mind;
}

int main(int argc, char const *argv[])
{
	int n; 
	double min;
	while(cin >> n && n)
	{
		for(int i = 0; i < n; i++){
			cin >> p[i].x >> p[i].y;
		}
		sort(p, p + n);
		min = findcp(0, n-1, n);
		if(min < 10000) printf("%.4lf\n", min);
		else printf("INFINITY\n");

	}
	return 0;
}