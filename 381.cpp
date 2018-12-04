#include "PE.h"

vector<int> primes = get_primes(100000000);

LL inv(LL a,LL p){
	LL ret = 1;
	LL n = p - 2;
	while(n > 0){
		if(n & 1) ret = ret * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ret;
}

int main(){
	LL ret = 0;
	LL sum = 0;
	for(auto p : primes){
		if(p >= 5){
			LL ans = p - 1;
			LL temp = p - 1;
			for(int i = 1;i <= 4;i++){
				temp = temp * inv(p - i,p) % p;
				ans = (ans + temp) % p;
			}
			ret += ans;	
			sum += p;
		}
	}
	cout << ret << endl;
	cout << sum << endl;
	return 0;
}
