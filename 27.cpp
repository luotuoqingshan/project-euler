#include "PE.h"

vector<int> B = get_primes(1000);

int main(){
	int ans = 0,ansp = 0;
	for(int a = -999;a < 1000;a++){
		for(int k = 0;k < B.size();k++){
			int b = B[k];
			int i;
			for(i = 0;;i++){
				long long x = 1LL * i * i + 1LL * a * i + b;
				if(x <= 0) break;
				if(!is_prime(x)) break;
			}	
			if(i > ans){
				ans = i;
				ansp = a * b;
			}
		}
	}
	cout << ans << " " << ansp << endl;

	return 0;
}
