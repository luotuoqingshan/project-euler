#include "PE.h"

vector<int> p = get_primes(2000000);
vector<int> phi = get_phi(2000000);

typedef long long LL;

LL qpow(LL a,LL n,LL p){
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ret;
}

vector<int> divisor(int n){
	vector<int> d(0);
	for(int i = 1;i * i <= n;i++){
		if(n % i == 0) {
			d.push_back(i);
			if(i != n / i){
				d.push_back(n / i);
			}
		}	
	}
	sort(d.begin(),d.end());
	return d;
}
int main(){
	cout << phi[1000023] << endl;
	for(int i = 1000001;i <= 1000200;i++){
		if(i % 2 == 0 || i % 5 == 0){
			continue;
		}
		int sum = 1;
		int ans = 1;
		while(sum % i != 0){
			sum = (sum * 10 + 1) % i;
			ans++;
		}
		if(ans > 1000000){
			cout << i << endl;
			break;
		}
	}	
	return 0;
}
