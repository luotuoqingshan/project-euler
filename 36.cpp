#include "PE.h"

bool check(int num){
	int d[30],n = 0;
	int a[30],m = 0;
	int tmp = num;
	while(tmp > 0){
		d[++n] = tmp % 10;
		tmp /= 10;
	}
	for(int i = 1;i <= n / 2;i++){
		if(d[i] != d[n + 1 - i]) return false;
	}
	tmp = num;
	while(tmp > 0){
		a[++m] = tmp % 2;
		tmp /= 2;
	}	
	for(int i = 1;i <= m / 2;i++){
		if(a[i] != a[m + 1 - i]) return false;
	}
	return true;
}

int main(){
	
	long long sum = 0;
	for(int i = 1;i < 1000000;i++){
		if(check(i)) sum += i;
	}
	cout << sum << endl;
	return 0;
}
