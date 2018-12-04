#include "PE.h"

typedef long long LL;

LL dp[105][5][2];

LL solve(int n){
	memset(dp,0,sizeof(dp));
	dp[0][0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= 2;j++){
			for(int k = 0;k <= 1;k++){
				dp[i][0][k] += dp[i - 1][j][k];
			}
		}//O
		for(int j = 0;j <= 2;j++){
			for(int k = 0;k <= 1;k++){
				dp[i][j + 1][k] += dp[i - 1][j][k];
			}
		}//A
		for(int j = 0;j <= 2;j++){
			dp[i][0][1] += dp[i - 1][j][0];
		}
	}
	LL ans = 0;
	for(int j = 0;j <= 2;j++){
		for(int k = 0;k <= 1;k++){
			ans += dp[n][j][k];
		}
	}
	return ans;
}

int main(){
	cout << solve(4) << endl;
	cout << solve(30) << endl;
	return 0;
}
