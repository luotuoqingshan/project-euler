#include "PE.h"

vector<int> prime = get_primes(1000);

int main(){
	int ans = 0;
	long long num = 0;
	for(int i = 0;i < prime.size();i++){
		long long now = 0;
		for(int j = i;j < i + ans;j++){
			now += prime[j];
		}
		int tmp = ans;
		for(int j = i + tmp;j < prime.size();j++){
			now += prime[j];
			if(now >= 1000) break;
			if(is_prime(now)){
				ans = j - i + 1;
				num = now;
			}
		}
	}
	cout << ans << " " << num << endl;

	return 0;
}
