#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[20][2][2][2];

void work(){
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= 16;i++){
		for(int j = 0;j < 2;j++){
			for(int k = 0;k < 2;k++){
				for(int l = 0;l < 2;l++){
					for(int tran = 0;tran < 16;tran++){
						if(tran == 0){
							dp[i][1][k][l] += dp[i - 1][j][k][l];
						}else if(tran == 1){
							dp[i][j][1][l] += dp[i - 1][j][k][l];
						}else if(tran == 10){
							dp[i][j][k][1] += dp[i - 1][j][k][l];
						}else{
							dp[i][j][k][l] += dp[i - 1][j][k][l];
						}
					}
				}
			}
		}
		for(int tran = 1;tran < 16;tran++){
			if(tran == 1){
				dp[i][0][1][0]++;
			}else if(tran == 10){
				dp[i][0][0][1]++;
			}else{
				dp[i][0][0][0]++;
			}
		}
	}
	dp[16][1][0][0]++;
	cout << dp[16][1][1][1] << endl;
}

int main(){
	work();
	long long tmp = dp[16][1][1][1];
	while(tmp > 0){
		int x = tmp % 16;
		tmp /= 16;
		if(x < 10) printf("%d",x);
		else{
			putchar('A' + x - 10);
		}
	}
	return 0;
}
