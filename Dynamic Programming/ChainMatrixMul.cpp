//intut matrix的矩陣大小, output最少需做幾次乘法
int M[1005][1005];
int P[1005][1005];
vector <int> d;
int do_dp(int i, int j){
	if(M[i][j] > 0) return M[i][j];
	if(i == j) return 0;
	int minx = 0xFFFFFFFF;
	for(int k = i ; k < j ; k++){
		if((do_dp(i, k) + do_dp(k+1, j) + d[i-1]*d[k]*d[j]) < minx){
			minx = do_dp(i, k) + do_dp(k+1, j) + d[i-1]*d[k]*d[j];
			P[i][j] = k;
		}
		//如果不用紀錄k是誰
		//minx = min(minx, do_dp(i, k) + do_dp(k+1, j) + d[i-1]*d[k]*d[j]);
	}
	return M[i][j] = minx;
}
int main(){
	int n, temp, s, ans;
	cin >> n;
	stringstream s1;
	string str;
	cin.ignore();
	while(n--){
		getline(cin, str);
		s1.clear();
		s1.str("");
		s1 << str;
		d.clear();
		while(s1 >> temp){
			d.push_back(temp);
		}
		s = d.size() - 1;
		memset(M, 0, sizeof(M));
		memset(P, 0, sizeof(P));
		ans = do_dp(1, s);
		printf("%d\n", ans);
	}
}