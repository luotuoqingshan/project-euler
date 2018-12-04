#include "PE.h"

const LL mod = 1e9 + 7;

LL qpow(LL a,LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

LL INV(LL n){
	return qpow(n,mod - 2);
}



int main(){
	LL n;
	cin >> n;
	LL sum = 0;
	for(LL k = 1;k <= n;k++){
		LL temp = qpow((1 - 1LL * k * k) % mod,n + 1);
		temp = (1 - temp + mod) % mod;
		LL fac = 1LL * k * k % mod;
		temp = temp * INV(fac) % mod;
		sum = (sum + temp - 1 + mod) % mod;
	}
	cout << sum << endl;
	return 0;
}
