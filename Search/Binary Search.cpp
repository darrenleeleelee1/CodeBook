int L = 0;     //  left boundary
int R = ans;   // right boundary
// check using L = 3, R = 4, ans = 4
while(L < R){
	int M = L + (R - L + 1) / 2;  // left + half distance
	if(ok(M)) L = M;		  // ok() method is to find  whether the M can qualify the demand
	else R = M - 1;
}

while(L < R){
	int M = L + (R - L) / 2;  // left + half distance
	if(ok(M)) R = M;		  // ok() method is to find  whether the M can qualify the demand
	else L = M + 1;
}

