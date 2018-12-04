#include "PE.h"


bool check(int x,int n){
	int num[10] = {0};
	for(int i = 1;i <= n;i++){
		int tmp = i * x;
		while(tmp > 0){
			num[tmp % 10]++;
			tmp /= 10;
		}	
	}
	for(int i = 1;i <= 9;i++){
		if(num[i] != 1) return false;
	}
	if(num[0] != 0) return false;
	return 1;
}


bool check(int x){
	for(int i = 2;i <= 9;i++){
		if(check(x,i)) return true;
	}
	return false;
}


int main(){
	int ans = 0;
	
	for(int i = 1;i <= 100000;i++){
		if(check(i)){
			cout << i << endl;
		}
	}	

	return 0;
}
