#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

double dp[1005][2];

int main(){
	dp[499][1] = 2; // dp[499][1] = 500 / 1000 * dp[499][1] + 500 / 1000 * 0 + 1
	dp[499][0] = 2 * (1 + 1.0 / 1000 * dp[499][1]);// 500 / 1000 * dp[499][0] + 1 / 1000 * 
	for(int i = 498;i >= 0;i--){
		dp[i][1] = (1000.0 / (999 - i)) * (1 + (998 - 2 * i) / 1000.0 * dp[i + 1][1]);// (i + 1) / 1000 * dp[i][1] + (i + 1) / 1000 * 0 + (998 - 2 * i) / 1000 * dp[i + 1][1] + 1;
		dp[i][0] = (1000.0 / (999 - i)) * (1 + 1 / 1000.0 * dp[i][1] + (998 - 2 * i) / 1000.0 * dp[i + 1][0]);
		//(i + 1) / 1000 + i / 1000 + 
	}
	printf("%.8lf\n",dp[0][0]);
	return 0;
}
