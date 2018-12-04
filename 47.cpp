#include "PE.h"



vector<int> p = get_primes(10000000);

int cal(int x){
	int tmp = x;
	int ret = 0;
	for(int i = 0;i < p.size() && p[i] * p[i] <= x;i++){
		if(x % p[i]) continue;
		ret++;
		while(tmp % p[i] == 0){
			tmp /= p[i];
		}	
	}
	if(tmp > 1) ret++;
	return ret;
}

int main(){
	for(int i = 1;i <= 1000000;i++){
		bool flag = true;
		for(int j = 0;j < 4;j++){
			if(cal(i + j) != 4) flag = false;	
		}
		if(flag){
			cout << i << endl;
			break;
		}
	}	
	return 0;
}
