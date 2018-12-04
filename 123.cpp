#include "PE.h"

vector<int> primes = get_primes(1000000);

int main(){
	for(int i = 1;i <= primes.size();i++){
		if(i % 2 == 0) continue;
		if(2LL * i * primes[i - 1] % (1LL * primes[i - 1] * primes[i - 1]) > 1e10){
			cout << i << endl;
			break;
		}
	}

	return 0;
}
