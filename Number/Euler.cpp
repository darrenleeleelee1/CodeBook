const int maxn = 50000;
int F[maxn+5];
void Euler(){
	memset(F, 0, sizeof(F));
	F[1] = 1;
	for(int i=2; i<maxn; i++){
		if(!F[i]){
			for(int j=i; j<maxn; j+=i){
				if(!F[j]) F[j] = j;
				F[j] = F[j] / i*(i-1);
			}
		}
	}
}