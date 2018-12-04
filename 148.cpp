#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[40][2][2][2];//l是否贴着上轮廓线，r是否贴着l的轮廓线，是否出现小于
int digit[40],tot;

long long cal(int x){
	memset(dp,0,sizeof(dp));
	tot = 0;
	while(x > 0){
		digit[++tot] = x % 7;
		x /= 7;
	}
	reverse(digit + 1,digit + 1 + tot);
	dp[0][1][1][0] = 1;
	for(int i = 0;i < tot;i++){
		for(int j = 0;j < 2;j++){
			for(int k = 0;k < 2;k++){
				if(j == 0 && k == 0){
					for(int d1 = 0;d1 < 7;d1++){
						for(int d2 = 0;d2 < 7;d2++){
							if(d2 > d1){
								dp[i + 1][j][k][1] += dp[i][j][k][0] + dp[i][j][k][1];
							}else{
								dp[i + 1][j][k][0] += dp[i][j][k][0];
								dp[i + 1][j][k][1] += dp[i][j][k][1];
							}
						}
					}
				}
				if(j == 1 && k == 0){
					for(int d1 = 0;d1 < digit[i + 1];d1++){
						for(int d2 = 0;d2 < 7;d2++){
							if(d2 > d1){
								dp[i + 1][0][0][1] += dp[i][j][k][0] + dp[i][j][k][1];
							}else{
								dp[i + 1][0][0][0] += dp[i][j][k][0];
								dp[i + 1][0][0][1] += dp[i][j][k][1];
							}	
						}
					}
					for(int d2 = 0;d2 < 7;d2++){
						if(d2 > digit[i + 1]){
							dp[i + 1][1][0][1] += dp[i][j][k][0] + dp[i][j][k][1];
						}else{
							dp[i + 1][1][0][0] += dp[i][j][k][0];
							dp[i + 1][1][0][1] += dp[i][j][k][1];
						}
					}
				}
				if(j == 0 && k == 1){
					for(int d1 = 0;d1 < 7;d1++){
						for(int d2 = 0;d2 < d1;d2++){
							dp[i + 1][0][0][0] += dp[i][0][1][0];
							dp[i + 1][0][0][1] += dp[i][0][1][1];
						}
						dp[i + 1][0][1][0] += dp[i][0][1][0];
						dp[i + 1][0][1][1] += dp[i][0][1][1];
					}
				}
				if(j == 1 && k == 1){
					for(int d1 = 0;d1 < digit[i + 1];d1++){
						for(int d2 = 0;d2 < d1;d2++){
							dp[i + 1][0][0][0] += dp[i][j][k][0];
							dp[i + 1][0][0][1] += dp[i][j][k][1];
						}
						dp[i + 1][0][1][0] += dp[i][j][k][0];
						dp[i + 1][0][1][1] += dp[i][j][k][1];
					}
					for(int d2 = 0;d2 < digit[i + 1];d2++){
						dp[i + 1][1][0][0] += dp[i][j][k][0];
						dp[i + 1][1][0][1] += dp[i][j][k][1];
					}
					dp[i + 1][1][1][0] += dp[i][j][k][0];
					dp[i + 1][1][1][1] += dp[i][j][k][1];
				}
			}
		}
	}	
	long long ans = 0;
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 2;j++){
			ans += dp[tot][i][j][1];
		}
	}
	return ans;
}

int main(){
	for(int i = 6;i <= 10;i++){
		cout << cal(i) << endl;
	}
	cout << cal(99) << endl;
	long long now = 1000000000;
	cout << now * (now + 1) / 2 - cal(now - 1) << endl;
	return 0;
}
