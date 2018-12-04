#include "PE.h"

long long dp[105][10];


long long cal(int len){
	memset(dp,0,sizeof(dp));
	for(int i = 1;i < 10;i++)
		dp[1][i] = 1;
	for(int i = 2;i <= len;i++){
		for(int j = 0;j < 10;j++){
			for(int k = 0;k <= j;k++){
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	long long ans = 0;
	for(int i = 0;i < 10;i++){
		ans += dp[len][i];
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1;i < 10;i++)
		dp[1][i] = 1;
	for(int i = 2;i <= len;i++){
		for(int j = 0;j < 10;j++){
			for(int k = j;k < 10;k++){
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	for(int i = 0;i < 10;i++){
		ans += dp[len][i];
	}
	return ans;
}

int main(){
	long long ans = 0;
	for(int i = 1;i <= 100;i++){
		ans += cal(i);
		ans -= 9;
	}
	cout << ans << endl;
	return 0;
}
