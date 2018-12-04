#include "PE.h"

long long dp[55];

long long cal(int n){
	dp[0] = 1;
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		if(i >= 2) dp[i] += dp[i - 2];
		if(i >= 3) dp[i] += dp[i - 3];
		if(i >= 4) dp[i] += dp[i - 4];
	}
	return dp[n];
}

int main(){
	cout << cal(50) << endl;

	return 0;
}
