#include "PE.h"

typedef long long LL;

const int mod = 1e9;

LL sum(LL x){
	if(x == 0) return 0;
	LL a = x,b = x + 1,c = 2 * x + 1;
	if(a % 2 == 0){
		a /= 2;	
	}else b /= 2;
	if(a % 3 == 0)
		a /= 3;
	else if(b % 3 == 0)
		b /= 3;
	else c /= 3;
	a %= mod;
	b %= mod;
	c %= mod;
	return a * b % mod * c % mod;
}

LL cal(LL n){

	LL ans = 0;
	LL x = n;
	while(true){
		LL y = (n / (n / x + 1));
		LL d = n / x;
		d %= mod;
		LL s = (sum(x) - sum(y) + mod) % mod;
		s = s * d % mod;
		ans = (ans + s) % mod;
		x = y;
		if(x < 1) break;
	}
	return ans;
}

int main(){
	for(int i = 1;i <= 6;i++){
		cout << cal(i) << endl;
	}
	cout << cal(1000000000000000LL) << endl;
	cout << cal(1e15) << endl;
	return 0;
}
