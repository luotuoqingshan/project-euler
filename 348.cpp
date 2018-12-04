#include "PE.h"


bool sqr(LL n){
	LL x = sqrt(n);
	return x * x == n;
}

LL change(LL n,bool flag){
	int tot = 0;
	int a[10];
	while(n > 0){
		a[++tot] = n % 10;
		n /= 10;
	}
	if(flag){
		for(int i = tot;i >= 1;i--){
			n = n * 10 + a[i];
		}
		for(int i = 1;i <= tot;i++){
			n = n * 10 + a[i];
		}
	}else{
		for(int i = tot;i >= 1;i--){
			n = n * 10 + a[i];
		}
		for(int i = 2;i <= tot;i++){
			n = n * 10 + a[i];
		}
	}
	return n;
}

bool check(LL n){
	int ret = 0;
	for(int i = 1;1LL * i * i * i <= n;i++){
		if(sqr(n - 1LL * i * i * i))
			ret++;
	}
	return ret >= 4;
}

int main(){
	int now = 1;
	long long sum = 0;
	int cnt = 0;
	for(now = 1;now <= 100000;now *= 10){
		for(int j = now;j < now * 10;j++){
			if(check(change(j,1))){
				cout << change(j,1) << endl;
				cnt++;
				if(cnt <= 5){
					sum += change(j,1);
				}	
				if(cnt == 5){
					cout << sum << endl;
					return 0;
				}
			}
		}
		for(int j = now;j < now * 10;j++){
			if(check(change(j,0))){
				cout << change(j,0) << endl;
				cnt++;
				if(cnt <= 5){
					sum += change(j,0);
				}	
				if(cnt == 5){
					cout << sum << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
