#include "PE.h"

int k,n;

typedef long double db;

const int maxn = 1e6 + 5;

db dp[maxn];

db fac[maxn];

db c(int n,int k){
	return fac[n] / fac[k] / fac[n - k];
}

int main(){
	int n,k;
	cin >> k >> n;
	for(int i = 0;i < maxn;i++){
		fac[i + 1] = fac[i] + log(i + 1.0);
	}
	db ans = 0;
	db now = 1;
	for(int j = 0;j * 2 <= k;j++){
		ans += c(n,j) * c(n - j,k - 2 * j) * fac[k] * now; 
		now /= 2;
	}
	for(int i = 1;i <= k;i++){
		ans = ans / n;
	}
	ans = 1 - ans;
	printf("%.10Lf\n",ans);
	return 0;
}
