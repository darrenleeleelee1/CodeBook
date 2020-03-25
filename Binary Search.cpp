int L = 0;     //  left boundary
int R = ans;   // right boundary

while(L < R){
	int M = L + (R + L) / 2;  // left + half distance
	if(ok(M)) L = M;		  // ok() method is to find  whether the M can qualify the demand
	else R = M - 1;
}