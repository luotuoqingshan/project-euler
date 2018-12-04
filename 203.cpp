#include "PE.h"

LL check(LL n,LL m,LL k){
	LL cnt1 = 0,cnt2 = 0;
	for(LL i = k;i <= n;i *= k){
		cnt1 += n / i;
	}
	for(LL i = k;i <= m;i *= k){
		cnt2 += m / i;
	}
	for(LL i = k;i <= n - m;i *= k){
		cnt2 += (n - m) / i;
	}
	if(cnt1 - cnt2 >= 2) return true;
	return false;
}

bool check(LL n){
	for(int i = 2;i <= 50;i++){
		if(n % (i * i) == 0) return false;
	}
	return true;
}

LL c[52][52];

void init(){
	c[0][0] = 1;
	for(LL i = 1;i <= 51;i++){
		c[i][0] = c[i][i] = 1;
		for(LL j = 1;j < i;j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}

set<LL> s;

int main(){
	init();
	int n;
	LL sum = 0;
	for(int i = 0;i < 51;i++){
		for(int j = 0;j <= i;j++){
			if(check(c[i][j])){
				s.insert(c[i][j]);
			}
		}
	}
	for(auto x : s){
		sum += x;
	}
	cout << sum << endl;
	return 0;
}
