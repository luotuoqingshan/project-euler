#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

long double dp[40];
long long c[40][40];

void init(){
	c[0][0] = 1;
	for(int i = 1;i <= 35;i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1;j < i;j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}


int main(){
	init();
	dp[32] = 0;	
	for(int i = 31;i >= 0;i--){
		int j = 32 - i;		
		long double ans = (1LL << j);
		for(int k = 1;k <= j;k++){
			ans += c[j][k] * dp[i + k];
		}
		dp[i] = ans / ((1LL << j) - 1);
	}
	printf("%.10Lf\n",dp[0]);
	return 0;
}
