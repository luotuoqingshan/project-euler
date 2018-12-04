#include "PE.h"

const LL N = 1e8;
const LL mod = 1e9 + 9;
vector<int> primes = get_primes(N);
vector<vector<LL> > ret = Fac(N, mod);
vector<LL> fac = ret[0];
vector<LL> inv = ret[1];

LL C(LL n, LL m){
	return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

LL cal(LL n){
	LL ret = C(2 * n, n);
	if(n == 2)
		ret -= 2 * (n - 1);
	else
		ret += 2 * (n - 1);
	ret = (ret % mod + mod) % mod;
	ret = ret * POW(n, mod - 2,mod) % mod;
	return ret;
}

int dp[55][55][55];

int A(int n,int q){
	memset(dp,0,sizeof(dp));
	dp[0][0][0] = 1;
	for(int i = 1;i <= n * q;i++){
		for(int j = 0;j < n;j++){
			for(int k = 0;k <= n;k++){
				dp[i][j][k] = dp[i - 1][j][k];
			}
			for(int k = 1;k <= n;k++){
				dp[i][j][k] += dp[i - 1][((j - i) % n + n) % n][k - 1];
			}
		}
	}	
	return dp[n * q][0][n];
}


int main(){
	/*
	LL ans = 0;
	for(auto x: primes){
		if(x > 100)
			break;
		ans = (ans + cal(x)) % mod;
	}
	cout << ans << endl;
	*/
	for(int i = 1;i <= 10;i++){
		cout << A(i,2) << endl;
	}
	return 0;
}



