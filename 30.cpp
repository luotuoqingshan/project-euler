#include "PE.h"

int f4(int x){
	return x * x * x * x * x;
}

bool cal(int n){
	int d[10],tot;
	tot = 0;
	int tmp = n;
	while(tmp > 0){
		d[tot++] = tmp % 10;
		tmp /= 10;
	}
	int sum = 0;
	for(int i = 0;i < tot;i++){
		sum += f4(d[i]);
	}
	return sum == n ;
}

int main(){
	int ans = 0;
	for(int i = 1;i <= 1000000;i++){
		if(cal(i)) ans += i;
	}	
	cout << ans << endl;
	return 0;
}
