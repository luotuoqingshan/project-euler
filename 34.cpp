#include "PE.h"


int fac[10];

bool check(int x){
	int tmp = x;
	int sum = 0;
	while(tmp > 0){
		sum += fac[tmp % 10];
		tmp /= 10;
	}
	if(sum == x) return true;
	return false;
}

int main(){
	fac[0] = 1;
	for(int i = 1;i <= 9;i++){
		fac[i] = fac[i - 1] * i;
	}
	long long sum = 0;
	for(int i = 3;i <= 1000000;i++){
		if(check(i)){
			sum += i;
		}
	}
	cout << sum << endl;	
	return 0;
}
