#include "PE.h"

int digit(int x){
	int tmp = x;
	int cnt = 0;
	while(tmp > 0){
		cnt++;
		tmp /= 10;
	}
	return cnt;
}
const int maxn = 1000000 + 5;
int a[maxn];

int cal(int n){
	int sum = 0;
	for(int i = 1;i < maxn;i++){
		sum += a[i];
		if(sum >= n){
			sum -= a[i];
			int b[10];
			int tot = 0;
			int tmp = i;
			while(tmp > 0){
				b[++tot] = tmp % 10;
				tmp /= 10;
			}
			reverse(b + 1,b + 1 + tot);
			return b[n - sum];
		}
	}	
	return 0;
}

int main(){
	for(int i = 1;i <= 1000000;i++){
		a[i] = digit(i);
	}
	int now = 1;
	int ans = 1;
	for(int i = 1;i <= 7;i++){
		ans *= cal(now);
		now *= 10;
	}
	cout << ans << endl;
	return 0;
}
