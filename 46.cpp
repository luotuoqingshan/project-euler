#include "PE.h"


vector<int> p = get_primes(1000000);

map<int,bool> sqr;


int main(){
	for(int i = 1;i <= 30000;i++){
		sqr[i * i] = 1;
	}
	for(int i = 35;;i += 2){
		if(is_prime(i)) continue;
		bool flag = false;
		for(int j = 0;j < p.size();j++){
			if(p[j] >= i) break;
			int val = i - p[j];
			if(val & 1) continue;
			val /= 2;
			if(sqr.count(val)) flag = true;
		}
		if(!flag){
			cout << i << endl;
			break;
		}
	}

	return 0;
}
