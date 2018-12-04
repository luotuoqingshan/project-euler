#include "PE.h"

long long dp[100];

long long cal(int m,int n){
	dp[0] = 1;
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		if(i >= m) dp[i]++;
		for(int j = m;j < i;j++){
			dp[i] += dp[i - j - 1];
		}	
	}
	return dp[n];
}

int main(){
	for(int i = 50;;i++){
		long long val = cal(50,i);
		if(val > 1000000LL){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
