#include "PE.h"

LL dp[25][1000];

int main(){
	for(int i = 1;i <= 9;i++){
		dp[1][i] = 1;
	}
	for(int i = 2;i <= 20;i++){
		for(int j = 0;j < 1000;j++){
			for(int k = 0;k < 10;k++){
				int v1 = j % 10;
				int v2 = (j / 10) % 10;
				if(v1 + v2 + k <= 9){
					dp[i][(j * 10 + k) % 1000] += dp[i - 1][j];
				}
			}
		}
	}
	LL ans = 0;
	for(int i = 0;i < 1000;i++){
		ans += dp[20][i];
	}
	cout << ans << endl;
	return 0;
}
