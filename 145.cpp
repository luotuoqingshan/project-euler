#include "PE.h"

int rev(int n){
	int temp[15],tot = 0;
	while(n > 0){
		temp[tot++] = n % 10;
		n /= 10;
	}
	int ret = 0;
	for(int i = 0;i < tot;i++){
		ret = ret * 10 + temp[i];
	}
	return ret;
}

bool check(int n){
	int temp[15],tot = 0;
	while(n > 0){
		temp[tot++] = n % 10;
		n /= 10;
	}
	for(int i = 0;i < tot;i++){
		if(temp[i] % 2 == 0) return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(i % 10 == 0) continue;
		if(check(i + rev(i))){
			ans++;	
		}
	}
	cout << ans << endl;
	return 0;
}
