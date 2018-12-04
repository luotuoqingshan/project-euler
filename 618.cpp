#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include "PE.h"

using namespace std;

int f[25];

const int maxn = 47005;

const int mod = 1e9;

void upd(int &a,int b){
	a += b;
	if(a >= mod)
		a -= mod;
}

int dp[maxn][5200];

vector<int> primes = get_primes(50000);



int main(){
	f[1] = 1;
	f[2] = 1;
	for(int i = 3;i <= 24;i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	dp[0][0] = 1;
	dp[1][0] = 0;
	for(int i = 0;i <= f[24];i++){
		if(i > 0) dp[i][0] = 0;
		for(int j = 1;j <= primes.size();j++){
			dp[i][j] = dp[i][j - 1];
			if(i >= primes[j - 1]){
				upd(dp[i][j],1LL * primes[j - 1] * dp[i - primes[j - 1]][j] % mod) ;
			}
		}
	}
	int sum = 0;
	for(int i = 2;i <= 24;i++){
		upd(sum,dp[f[i]][primes.size()]);
	}
	cout << sum << endl;
	return 0;
}
