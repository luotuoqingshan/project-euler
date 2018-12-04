#include "PE.h"

long long dp[50][10][(1 << 10) + 5];

long long cal(int len){
	memset(dp,0,sizeof(dp));
	for(int i = 1;i < 10;i++){
		dp[1][i][(1 << i)] = 1;
	}
	for(int i = 2;i <= len;i++){
		for(int j = 0;j < 10;j++){
			for(int k = 0;k < (1 << 10);k++){
				for(int l = 0;l < 10;l++)
					if(abs(l - j) == 1) 
						dp[i][l][k | (1 << l)] += dp[i - 1][j][k];
			}
		}
	}
	long long ans = 0;
	for(int i = 0;i < 10;i++){
		ans += dp[len][i][(1 << 10) - 1];
	}	
	return ans;
}

int main(){
	long long ans = 0;
	cout << cal(10) << endl;
	
	for(int i = 1;i <= 40;i++){
		ans += cal(i);
	}
	cout << ans << endl;
	return 0;
}
