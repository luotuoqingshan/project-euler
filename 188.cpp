#include "PE.h"

const int mod = 1e8;

int qpow(int a,int n,int mod){
	int ret = 1;
	while(n > 0){
		if(n & 1)
			ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ret;
}

int phi(int n){
	if(n % 2 == 0) n /= 2;
	if(n % 5 == 0) n = n / 5 * 4;
	return n;
}

int cal(int a,int k,int mod){
	if(mod == 1){
		return 0;
	}
	return qpow(a,cal(a,k - 1,phi(mod)) % phi(mod),mod);
}

int main(){
	cout << cal(1777,1855,100000000);	

	return 0;
}
