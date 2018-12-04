#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[40][2];

int main(){
	dp[0][0] = 1;
	for(int i = 1;i <= 30;i++){
		dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] += dp[i - 1][0];
	}
	cout << dp[30][0] + dp[30][1] << endl;
	return 0;
}
