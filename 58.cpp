#include "PE.h"


int main(){
	int cnt = 8;
	for(int i = 9;;i += 2){
		int a = i * i,b = i * i - (i - 1),c = i * i - 2 * (i - 1),d = i * i - 3 * (i - 1);
		if(is_prime(a)) cnt++;
		if(is_prime(b)) cnt++;
		if(is_prime(c)) cnt++;
		if(is_prime(d)) cnt++;
		if(1.0 * cnt / (2 * i - 1) < 0.1){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
