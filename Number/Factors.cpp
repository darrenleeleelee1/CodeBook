vector<int> getDivisiors(int x){
	vector<int> res;
	int sq = (int) sqrt(x + 0.5 );
	for(int i = 1; i <= sq; i++){
		if(x % i == 0) {
			int j = x / i;
			res.push_back(i);
			if(i != j) res.push_back(j);
		}
	}
	return res;
}