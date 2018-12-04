#include "PE.h"

const LL mod = 1e9 + 9;

LL n;

LL qpow(LL a,LL m){
	LL ret = 1;
	while(m > 0){
		if(m & 1){
			ret = ret * a % mod;
		}
		a = a * a % mod;
		m >>= 1;
	}
	return ret;
}

LL cal(LL x,LL n){
	LL cnt = 0;
	for(LL a = x;a <= n;a *= x){
		cnt += n / a;
	}
	return (1 + qpow(x,(2 * cnt)) % mod) % mod;
}

vector<int> primes = get_primes(2e8);

LL solve(LL n){
	LL ans = 1;
	for(auto x:primes){
		if(x > n) break;
		ans = (ans * cal(x,n)) % mod;
	}
	return ans;
}

LL gcd(LL a,LL b){
	return b == 0 ? a : gcd(b,a % b);
}

int main(){
	cin >> n;
	cout << solve(n) << endl;
	cout << primes[primes.size() - 1] << endl;
/*	LL x = 1;
	for(int i = 1;i <= n;i++){
		x = x * i;
	}
	LL ans = 0;
	for(int i = 1;i <= x;i++){
		if(x % i == 0){
			if(gcd(i,x / i) == 1){
				ans = (ans + 1LL * i * i) % mod;
			}
		}
	}
	cout << ans << endl;*/
	return 0;
}
